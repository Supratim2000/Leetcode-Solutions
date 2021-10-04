class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1000000007;
        long long count=0;
        int n=nums.size();
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++)
            dp[i]=(2*dp[i-1])%mod;
        sort(nums.begin(),nums.end());
        int l=0;
        int h=n-1;
        while(l<=h)
            nums[l]<=target-nums[h]?count+=(dp[h-(l++)+1]%mod):h--;
        return (int)(count%mod);
    }
};
