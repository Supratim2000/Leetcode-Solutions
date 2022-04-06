//Approach 1(Union Find)
class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int v)
        {
            for(int i=0;i<=v;i++)
            {
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        
        int find(int v)
        {
            if(v==parent[v])
                return v;
            int leader=find(parent[v]);
            parent[v]=leader;
            return leader;
        }
    
        void Union(int u, int v)
        {
            int lu=find(u);
            int lv=find(v);
            if(lu!=lv)
            {
                if(rank[lu]>rank[lv])
                    parent[lv]=lu;
                else if(rank[lu]<rank[lv])
                    parent[lu]=lv;
                else
                {
                    parent[lv]=lu;
                    rank[lu]++;
                }
            }
        }    
};
class Solution {
public:
    int getUnique(int i,int j,int numCol){return i*numCol+j;}
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid.at(0).size();
        int count=0;
        DSU* dsu=new DSU(r*c);
        unordered_set<int> included;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    int smallestIsland=true;
                    if(i+1<r && grid[i+1][j]=='1')
                    {
                        dsu->Union(getUnique(i,j,c),getUnique(i+1,j,c));
                        included.insert(getUnique(i,j,c));
                        included.insert(getUnique(i+1,j,c));
                        smallestIsland=false;
                    }
                    if(j+1<c && grid[i][j+1]=='1')
                    {
                        dsu->Union(getUnique(i,j,c),getUnique(i,j+1,c));
                        included.insert(getUnique(i,j,c));
                        included.insert(getUnique(i,j+1,c));
                        smallestIsland=false;
                    }
                    if(smallestIsland=true)
                        included.insert(getUnique(i,j,c));
                }
            }
        }
        for(auto x: included)
            if(dsu->parent[x]==x)
                count++;
        return count;
    }
};

//Approach 2(DFS)
class Solution {
public:
    void markConnectedVisited(vector<vector<char>>& grid, int i, int j, int r, int c, vector<vector<bool>>& vis, vector<pair<int,int>>& direction)
    {
        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]=='0' || vis[i][j])
            return;
        vis[i][j]=true;
        for(int x=0;x<4;x++)
            markConnectedVisited(grid,i+direction.at(x).first,j+direction.at(x).second,r,c,vis,direction);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid.at(0).size();
        vector<pair<int,int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    markConnectedVisited(grid,i,j,r,c,vis,direction);
                }
            }
        }
        return count;
    }
};
