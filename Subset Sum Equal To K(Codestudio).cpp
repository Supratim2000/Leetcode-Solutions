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
