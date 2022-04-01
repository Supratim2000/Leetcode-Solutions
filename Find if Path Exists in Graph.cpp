class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            if(curNode==end)
                return true;
            for(auto x: adj[curNode])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        return false;
    }
};
