class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> ans;
        queue<int> q;
        vector<int> indeg(n,0);
        vector<int> adj[n];

        for(auto x: prerequisites)
            adj[x[1]].push_back(x[0]);

        for(int i=0;i<prerequisites.size();i++)
            indeg[prerequisites[i][0]]++;

        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);

        while(!q.empty())
        {
            int curNode=q.front();
            ans.push_back(curNode);
            q.pop();
            for(auto adjNode: adj[curNode])
            {
                indeg[adjNode]--;
                if(indeg[adjNode]==0)
                    q.push(adjNode);
            }
        }

        if(ans.size()!=numCourses)
            ans.clear();

        return ans;
    }
};
