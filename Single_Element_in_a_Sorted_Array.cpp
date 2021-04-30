class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=-1;
        int size=nums.size();
        int l=0;
        int h=size-1;
        
        if(size==1)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[h]!=nums[h-1])
                return nums[h];
        else
        {
            while(l<=h)
            {
                int mid=l+((h-l)/2);
                if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                {
                    ans=nums[mid];
                    break;
                }
                else if(mid%2==0 && nums[mid]==nums[mid-1])
                    h=mid-2;
                else if(mid%2==0 && nums[mid]==nums[mid+1])
                    l=mid+2;
                else if(mid%2!=0 && nums[mid]==nums[mid+1])
                    h=mid-1;
                else if(mid%2!=0 && nums[mid]==nums[mid-1])
                    l=mid+1;
            }
            return ans;
        }
    }
};
