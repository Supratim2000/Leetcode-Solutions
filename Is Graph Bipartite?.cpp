//BFS
class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, vector<int>& color, int node)
    {
        bool isComponentBipartite=true;
        int n=graph.size();
        queue<int> q;
        q.push(node);
        color[node]=0; //starting color black
        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            for(auto neighbour: graph[curNode])
            {
                //neighbour node not colored
                if(color[neighbour]==-1)
                {
                    int curColor=color[curNode];
                    color[neighbour]=(curColor==0?1:0);
                    q.push(neighbour);
                }
                else if(color[curNode]==color[neighbour])
                {
                    isComponentBipartite=false;
                    break;
                }
            }
        }
        return isComponentBipartite;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        bool isGraphBipartite=true;
        /*
          -1 -> non-colored
          0 -> black
          1 -> white
        */
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!checkBipartite(graph,color,i))
                {
                    isGraphBipartite=false;
                    break;
                }
            }
        }
        return isGraphBipartite;
    }
};

//DFS
class Solution {
public:
    void checkBipartite(vector<vector<int>>& graph, vector<int>& color, bool& flag, int node)
    {
        for(auto adjNode: graph[node])
        {
            if(color[adjNode]==-1)
            {
                color[adjNode]=(color[node]==0?1:0);
                checkBipartite(graph,color,flag,adjNode);
            }
            else if(color[node]==color[adjNode])
            {
                flag=false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        bool isGraphBipartite=true;
        /*
          -1 -> non-colored
          0 -> black
          1 -> white
        */
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0; //black
                checkBipartite(graph,color,isGraphBipartite,i);
            }
        }
        return isGraphBipartite;
    }
};
