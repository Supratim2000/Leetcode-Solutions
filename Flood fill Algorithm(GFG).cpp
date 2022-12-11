class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int initCol=image[sr][sc];
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j]=image[i][j];
        dfs(sr,sc,n,m,initCol,newColor,image,ans);
        return ans;
    }
    
    void dfs(int r, int c, int n, int m, int initCol, int newCol, vector<vector<int>>& oldMat, vector<vector<int>>& newMat)
    {
        newMat[r][c]=newCol;
        if(r-1>=0 && oldMat[r-1][c]==initCol && newMat[r-1][c]!=newCol)
            dfs(r-1, c, n, m, initCol, newCol, oldMat, newMat);
        if(r+1<n && oldMat[r+1][c]==initCol && newMat[r+1][c]!=newCol)
            dfs(r+1, c, n, m, initCol, newCol, oldMat, newMat);
        if(c-1>=0 && oldMat[r][c-1]==initCol && newMat[r][c-1]!=newCol)
            dfs(r, c-1, n, m, initCol, newCol, oldMat, newMat);
        if(c+1<m && oldMat[r][c+1]==initCol && newMat[r][c+1]!=newCol)
            dfs(r, c+1, n, m, initCol, newCol, oldMat, newMat);
    }
};
