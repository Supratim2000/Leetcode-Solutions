//BFS approach
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool cycleDetect(int src,bool* vis, vector<int> adj[])
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;
        while(!q.empty())
        {
            pair<int,int> cur=q.front();
            q.pop();
            int node=cur.first;
            int par=cur.second;
            for(int i=0;i<adj[node].size();i++)
            {
                if(!vis[adj[node][i]])
                {
                    q.push({adj[node][i],node});
                    vis[adj[node][i]]=true;
                }
                else
                {
                    if(adj[node][i]!=par)
                        return true;
                }
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    int n=V;
	    bool* vis=new bool[n];
	    for(int i=0;i<n;i++)
	        vis[i]=false;
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i] && cycleDetect(i,vis,adj))
	        {
	            return true;
	        }
	    }
	    return false;
	}
};


//DFS approach
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool cycleDetect(int src,int par,bool* vis, vector<int> adj[])
    {
        vis[src]=true;
        for(int i=0;i<adj[src].size();i++)
        {
            if(!vis[adj[src][i]])
            {
                if(cycleDetect(adj[src][i],src,vis,adj))
                    return true;
            }
            else
            {
                if(adj[src][i]!=par)
                    return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    int n=V;
	    bool* vis=new bool[n];
	    for(int i=0;i<n;i++)
	        vis[i]=false;
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        {
	            if(cycleDetect(i,-1,vis,adj))
	                return true;
	        }
	    }
	    return false;
	}
};
