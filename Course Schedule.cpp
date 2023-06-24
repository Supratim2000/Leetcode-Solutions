//Method-1(BFS Kahns Algorithm)
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


//Method-2(DFS Cycle detection algorithm in directed graph)
class Solution {
private:
    bool checkCycle(vector<int> graph[],int n,int src,vector<bool>& vis,vector<bool>& dfsVis)
    {
        vis[src]=true;
        dfsVis[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            int curNode=graph[src][i];
            if(!vis[curNode] && checkCycle(graph,n,curNode,vis,dfsVis))
                return true;
            else if(dfsVis[curNode])
                return true;
        }
        dfsVis[src]=false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool hasCycle=false;
        vector<int> adj[numCourses];
        vector<bool> vis(numCourses, false);
        vector<bool> dfsVis(numCourses, false);

        //Creating adjacency list
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);
        for(int i=0;i<numCourses;i++)
        {
            if(checkCycle(adj,numCourses,i,vis,dfsVis))
            {
                hasCycle=true;
                break;
            }
        }

        return !hasCycle;
    }
};
