class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int i=0;
        while(i<=h)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[l]);
                i++;
                l++;
            }
            else if(nums[i]==1)
                i++;
            else
            {
                swap(nums[i],nums[h]);
                h--;
            }
        }
    }
};
