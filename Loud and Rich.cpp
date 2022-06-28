//DFS with memoization
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
            int insideQtNode=dfs(x,adj,quiet,ans);
            if(quiet[insideQtNode]<minQt)
            {
                minQt=quiet[insideQtNode];
                minQtNode=insideQtNode;
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

//Topological Sort
class Solution {
public:
    void topo(vector<vector<int>>& adj,vector<int>& quiet,vector<int>& indeg,vector<int>& ans)
    {
        int n=indeg.size();
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(auto x: adj[cur])
            {
                if(quiet[ans[cur]]<quiet[ans[x]])
                    ans[x]=ans[cur];
                indeg[x]--;
                if(indeg[x]==0)
                    q.push(x);
            }
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=i;
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto x: richer)
        {
            adj[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        topo(adj,quiet,indeg,ans);
        return ans;
    }
};
