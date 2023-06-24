class Solution {
private:
    bool kahnsAlgo(int n, vector<int> adj[])
    {
        vector<int> indeg(n,0);
        int count=0;
        queue<int> q;
        //Calculating indegrees of all nodes of the graph
        for(int i=0;i<n;i++)
            for(int j=0;j<adj[i].size();j++)
                indeg[adj[i][j]]++;
        
        //Pushing nodes with indegree zero
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);
        
        while(!q.empty())
        {
            int curNode=q.front();
            count++;
            q.pop();
            for(auto adjNode: adj[curNode])
            {
                indeg[adjNode]--;
                if(indeg[adjNode]==0)
                    q.push(adjNode);
            }
        }
        
        return count==n?true:false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        //Creating adjacency list
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);

        return kahnsAlgo(numCourses,adj);
    }
};
