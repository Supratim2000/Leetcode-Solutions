class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int blue=1;
        int red=2;
        vector<int> adj[n+1];
        for(auto x: dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> col(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)
            {
                queue<int> qu;
        	    qu.push(i);
        	    col[i]=blue;
        	    while(!qu.empty())
        	    {
        	        int curNode=qu.front();
        	        qu.pop();
        	        for(auto x: adj[curNode])
        	        {
        	            if(col[x]==0)
        	            {
        	                qu.push(x);
        	                col[curNode]==blue?col[x]=red:col[x]=blue;
        	            }
        	            else if(col[curNode]==col[x])
        	                    return false;
        	        }
	            }
            }
        }
        return true;
    }
};
