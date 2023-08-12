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
