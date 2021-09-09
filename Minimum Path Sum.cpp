//Recursive(TLE)
class Solution {
public:
    int mps(vector<vector<int>>& grid,int i,int j,int r,int c)
    {
        if(i==r-1 && j==c-1)
            return grid[i][j];
        if(i==r || j==c)
            return INT_MAX;
        return grid[i][j]+min(mps(grid,i+1,j,r,c),mps(grid,i,j+1,r,c));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        return mps(grid,0,0,r,c);
    }
};

//Memoized Solution
class Solution {
public:
    int mps(vector<vector<int>>& grid,int i,int j,int r,int c,vector<vector<int>>& dp)
    {
        if(i==r-1 && j==c-1)
            return grid[i][j];
        if(i==r || j==c)
            return INT_MAX;
        if(dp[i][j]==-1)
            dp[i][j]=min(mps(grid,i+1,j,r,c,dp),mps(grid,i,j+1,r,c,dp));
        return grid[i][j]+dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        return mps(grid,0,0,r,c,dp);
    }
};
