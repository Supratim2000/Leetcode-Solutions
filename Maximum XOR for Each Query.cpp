class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int numXor=(2<<(maximumBit-1))-1;
        vector<int> prefix(n,0);
        vector<int> ans(n,0);
        prefix[0]=nums[0];
        ans[n-1]=nums[0]^numXor;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]^nums[i];
            ans[n-i-1]=prefix[i]^numXor;
        }
        return ans;
    }
};
