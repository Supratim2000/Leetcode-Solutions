//Normal Recursive solution(TLE)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        return uniquePaths(m,n-1)+uniquePaths(m-1,n);
    }
};

//Memoization Solution
class Solution {
public:
    int up(int m, int n, vector<vector<int>>& dp)
    {
        if(m==1 || n==1)
            return 1;
        if(dp[m][n]==-1)
           dp[m][n]=up(m,n-1,dp)+up(m-1,n,dp);
        return dp[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return up(m,n,dp);
    }
};

//DP solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                (i==0 || j==0)?dp[i][j]=1:dp[i][j]=0;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};
