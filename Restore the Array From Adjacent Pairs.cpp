class Solution {
public:
    void dfs(int start,vector<int>& ans,unordered_map<int,vector<int>>& adj,unordered_set<int>& vis)
    {
        vis.insert(start);
        ans.push_back(start);
        for(int i=0;i<adj[start].size();i++)
        {
            if(vis.find(adj[start][i])==vis.end())
                dfs(adj[start][i],ans,adj,vis);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        int start=INT_MIN;
        vector<int> ans;
        unordered_map<int,vector<int>> adj;
        unordered_set<int> vis;
        for(int i=0;i<n;i++)
        {
            adj[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adj[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        for(auto x: adj)
        {
            if(x.second.size()==1)
            {
                start=x.first;
                break;
            }
        }
        dfs(start,ans,adj,vis);
        return ans;
    }
};
