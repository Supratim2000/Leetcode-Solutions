class Solution {
public:
    void dfs(int src, int par,unordered_set<int> eadj[], vector<int> adj[], vector<bool>& vis,int& count)
    {
        vis[src]=true;
        if(par!=-1 && eadj[par].find(src)!=eadj[par].end())
            count++;
        for(auto x: adj[src])
            if(!vis[x])
                    dfs(x,src,eadj,adj,vis,count);
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> eadj[n];
        vector<int> adj[n];
        vector<bool> vis(n,false);
        int count=0;
        for(auto x: connections)
        {
            eadj[x[0]].insert(x[1]);
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1,eadj,adj,vis,count);
        return count;
    }
};
