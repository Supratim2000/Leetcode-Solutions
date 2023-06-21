class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.at(0).size();
        int numFresh=0;
        int numRotten=0;
        int time=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        //(up,left,down,right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    numFresh++;
                else if(grid[i][j]==2)
                {
                    numRotten++;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            int queueSize=q.size();
            while(queueSize--)
            {
                pair<int,int> cur=q.front();
                int curx=cur.first;
                int cury=cur.second;
                vis[curx][cury]=true;
                q.pop();

                //Traversing 4 positions
                for(int i=0;i<4;i++)
                {
                    int newx=curx+dx[i];
                    int newy=cury+dy[i];
                    if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]==1 && !vis[newx][newy])
                    {
                        numFresh--;
                        numRotten++;
                        vis[newx][newy]=true;
                        q.push({newx,newy});
                    }
                }   
            }
            time++;
        }

        if(numFresh==0)
        {
            if(numRotten==0)
                return 0;
            else
                return count-1;
        }
        else
            return -1;
    }
};
