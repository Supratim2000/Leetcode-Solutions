class Solution {
public:
    int dfs(int cur,vector<vector<int>>& adj,vector<int>& quiet,vector<int>& ans)
    {
        if(ans[cur]!=-1)
            return ans[cur];
        int minQt=quiet[cur];
        int minQtNode=cur;
        for(auto x:adj[cur])
        {
            int adjQtNode=dfs(x,adj,quiet,ans);
            if(quiet[adjQtNode]<minQt)
            {
                minQt=quiet[adjQtNode];
                minQtNode=adjQtNode;
            }
        }
        ans[cur]=minQtNode;
        return minQtNode;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n,-1);
        vector<vector<int>> adj(n);
        for(auto x: richer)
            adj[x[1]].push_back(x[0]);
        for(int i=0;i<n;i++)
            dfs(i,adj,quiet,ans);
        return ans;
    }
};
