//Memoization
#include <bits/stdc++.h> 

bool fun(vector<int> &arr, vector<vector<int>> &dp, int n, int i, int target)
{
    if(target==0)
        return true;
    if(target<0)
        return false;
    if(i==0)
        return target==arr[0];
    if(dp[i][target]!=-1)
        return dp[i][target];
    bool take=fun(arr,dp,n,i-1,target-arr[i]);
    bool notTake=fun(arr,dp,n,i-1,target);
    bool posibility= take || notTake;
    dp[i][target]=posibility?1:0;
    return posibility;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return fun(arr,dp,n,n-1,k);
}

//Tabulation
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            bool notTake=dp[i-1][j];
            bool take=false;
            if(j-arr[i]>=0)           
                take=dp[i-1][j-arr[i]];
            dp[i][j]= take || notTake;
        }
    }
    return dp[n-1][k];    
}
