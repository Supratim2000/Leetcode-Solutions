//Memoization
class Solution {
public:
    int uniquePathCount(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int n, int m) {
        if(i==n-1 && j==m-1)
            return dp[i][j]=1;
        if(i>=n || j>=m || grid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int rightPath=uniquePathCount(grid, dp, i, j+1,n,m);
        int leftPath=uniquePathCount(grid, dp, i+1, j,n,m);
        return dp[i][j]=rightPath+leftPath;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid.at(0).size();

        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1)
            return 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));

        uniquePathCount(obstacleGrid,dp,0,0,n,m);

        return dp[0][0];
    }
};

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid.at(0).size();

        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1)
            return 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));

        bool flag1=false;
        bool flag2=false;

        for(int j=0;j<m;j++) {
            if(obstacleGrid[0][j]==1)
                flag1=true;
            if(flag1)
                dp[0][j]=0;
            else
                dp[0][j]=1;
        }

        for(int i=0;i<n;i++) {
            if(obstacleGrid[i][0]==1)
                flag2=true;
            if(flag2)
                dp[i][0]=0;
            else
                dp[i][0]=1;
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};
