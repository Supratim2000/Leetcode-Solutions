class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int ans=0;

        //(up,left,down,right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        //Traversing the 0'th row and n-1'th row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
                q.push({0,i});
            if(grid[n-1][i]==1)
                q.push({n-1,i});
        }

        //Traversing the 0'th column and m-1'th column
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0]==1)
                q.push({i,0});
            if(grid[i][m-1]==1)
                q.push({i,m-1});
        }

        while(!q.empty())
        {
            pair<int,int> curPos=q.front();
            int curx=curPos.first;
            int cury=curPos.second;
            vis[curx][cury]=true;
            q.pop();

            //Traversing 4 positions
            for(int i=0;i<4;i++)
            {
                int newx=curx+dx[i];
                int newy=cury+dy[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && grid[newx][newy]==1)
                {
                    vis[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    ans++;
            }
        }

        return ans;
    }
};
