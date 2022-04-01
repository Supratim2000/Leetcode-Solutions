class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int blue=1;
        int red=2;
        int n=graph.size();
        vector<int> col(n,0);
        for(int i=0;i<n;i++)
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
        	        for(auto x: graph[curNode])
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
