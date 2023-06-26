class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, unordered_set<int>& st, int& travelled) {
        if(vis[node] || st.find(node)!=st.end())
            return;
        travelled++;
        vis[node]=true;
        for(auto adjNode: adj[node])
            dfs(adjNode,adj,vis,st,travelled);    
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        unordered_set<int> st;
        vector<bool> vis(n,false);
        int travelled=0;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<restricted.size();i++)
            st.insert(restricted.at(i));

        dfs(0,adj,vis,st,travelled);

        return travelled;
    }
};
