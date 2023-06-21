class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        int count=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> s;
        queue<pair<int,int>> q;
        
        //(up,left,down,right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int basex=i;
                int basey=j;
                
                if(grid[i][j]==1 && !vis[i][j])
                {
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
                        //s.insert({relx,rely});
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
                
            }
        }
        
        count=s.size();
        
        return count;
    }
};
