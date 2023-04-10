//Memoization
//Time Complexity:- O(n^2)
//Space Complexity:- O(n^2)
class Solution {
public:
    int fun(int i, int j, int n, vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==n-1)
            return triangle[n-1][j];
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        int down=triangle[i][j]+fun(i+1,j,n,triangle,dp);
        int diag=triangle[i][j]+fun(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return fun(0,0,triangle.size(),triangle,dp);
    }
};

//Tabulation
//Time Complexity:- O(n^2)
//Space Complexity:- O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==n-1)
                    dp[i][j]=triangle[n-1][j];
                else
                {
                    int down=triangle[i][j]+dp[i+1][j];
                    int diag=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(down,diag);
                }
            }
        }
        return dp[0][0];
    }
};


//Space Optimization
//Time Complexity:- O(n^2)
//Space Complexity:- O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n);
        for(int i=0;i<n;i++)
            prev[i]=triangle[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            vector<int> cur(i+1);
            for(int j=0;j<=i;j++)
            {
                int down=triangle[i][j]+prev[j];
                int diag=triangle[i][j]+prev[j+1];
                cur[j]=min(down,diag);
            }
            for(int x=0;x<=i;x++)
                prev[x]=cur[x];
        }
        return prev[0];
    }
};
