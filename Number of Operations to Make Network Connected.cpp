class Solution {
public:
    void dfs(int src,vector<vector<int>>& adj,vector<bool>& vis)
    {
        vis[src]=true;
        for(auto x: adj[src])
            if(!vis[x])
                dfs(x,adj,vis);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int conComp=0;
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                conComp++;
            }
        }
        return connections.size()>=n-1?conComp-1:-1;
    }
};
