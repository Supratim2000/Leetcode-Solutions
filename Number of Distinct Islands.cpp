class Solution {
  public:
    void bfsFill(vector<vector<int>>& grid, queue<pair<int,int>> q, vector<vector<bool>>& vis, set<vector<pair<int,int>>>& s, int basex, int basey) {
        //(up,left,down,right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        int n=grid.size();
        int m=grid.at(0).size();
        vector<pair<int,int>> vec;
        q.push({basex,basey});

        while(!q.empty())
        {
            pair<int,int> curPos=q.front();
            int curx=curPos.first;
            int cury=curPos.second;
            int relx=curx-basex;
            int rely=cury-basey;
            vis[curx][cury]=true;
            vec.push_back({relx,rely});
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int newx=curx+dx[i];
                int newy=cury+dy[i];
                
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1 && !vis[newx][newy])
                {
                    vis[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }
        s.insert(vec);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        int count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> s;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    bfsFill(grid,q,vis,s,i,j);
            }
        }
        count=s.size();
        
        return count;
    }
};
