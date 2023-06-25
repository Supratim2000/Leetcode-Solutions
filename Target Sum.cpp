class Solution {
private:
    int ways(vector<int>& nums, int n, int target, vector<vector<int>>& dp, int sum, int i) {
        if(i==n)
            return sum==target?1:0;

        if(dp[i][sum+1000]!=-1)
            return dp[i][sum+1000];

        int wayMinus=ways(nums,n,target,dp,sum-nums.at(i),i+1);
        int wayPlus=ways(nums,n,target,dp,sum+nums.at(i),i+1);

        return dp[i][sum+1000]=wayPlus+wayMinus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++)
            sum+=abs(nums.at(i));
        if(target<=sum) {
            vector<vector<int>> dp(20,vector<int>(2001,-1));
            count=ways(nums,n,target,dp,0,0);
        }
        return count;
    }
};
