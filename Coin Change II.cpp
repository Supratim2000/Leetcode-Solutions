//Memoization
class Solution {
public:
    int helper(int amount,int i, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount<0)
            return 0;
        if(amount==0)
            return dp[amount][i]=1;
        if(i==0)
        {
            if(amount%coins[0]==0)
                return dp[amount][i]=1;
            else
                return dp[amount][i]=0;
        }

        if(dp[amount][i]!=-1)
            return dp[amount][i];

        int left=helper(amount-coins[i],i,coins,dp);
        int right=helper(amount,i-1,coins,dp);

        return dp[amount][i]=left+right;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        helper(amount,n-1,coins,dp);
        return dp[amount][n-1];
    }
};

//Tabulation
