class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1])
            return nums[0];
        int l=0;
        int h=n-1;
        int ans=nums[0];
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>=nums[0])
                l=mid+1;
            else
            {
                ans=nums[mid];
                h=mid-1;
            }
        }
        return ans;  
    }
};
