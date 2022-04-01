class Solution {
public:
    void dfs(int src,vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans, int v)
    {
        path.push_back(src);
        if(src==v-1)
            ans.push_back(path);
        for(auto x: graph[src])
            dfs(x,graph,path,ans,v);
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0,graph,path,ans,graph.size());
        return ans;
    }
};
