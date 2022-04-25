class Solution {
public:
    int rec(vector<int> nums, int n)
    {
        if(n==1) return nums.at(0);
        vector<int> smallAns(n-1);
        for(int i=0;i<n-1;i++)
            smallAns[i]=(nums[i]+nums[i+1])%10;
        return rec(smallAns,n-1);
    }
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        return rec(nums,n);
    }
};
