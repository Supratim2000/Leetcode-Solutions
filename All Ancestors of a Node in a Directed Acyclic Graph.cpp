//Approach 1
class Solution {
public:
    void dfs(int src,vector<int> adj[],vector<bool>& vis)
    {
        vis[src]=true;
        for(auto x: adj[src])
            if(!vis[x])
                dfs(x,adj,vis);
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<int> adj[n];
        for(auto x: edges)
            adj[x[0]].push_back(x[1]);
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            dfs(i,adj,vis);
            for(int j=0;j<n;j++)
                if(vis[j] && j!=i)
                    ans[j].push_back(i);
        }
        return ans;
    }
};
