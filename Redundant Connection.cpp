class DSU {
    public:
        bool hasCycle=false;
        vector<int> parent;
        vector<int> rank;
        DSU(int v)
        {
            for(int i=0;i<=v;i++)
            {
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        
        int find(int v)
        {
            if(v==parent[v])
                return v;
            int leader=find(parent[v]);
            parent[v]=leader;
            return leader;
        }
    
        void Union(int u, int v)
        {
            int lu=find(u);
            int lv=find(v);
            if(lu!=lv)
            {
                if(rank[lu]>rank[lv])
                    parent[lv]=lu;
                else if(rank[lu]<rank[lv])
                    parent[lu]=lv;
                else
                {
                    parent[lv]=lu;
                    rank[lu]++;
                }
            }
            else
                hasCycle=true;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU* dsu=new DSU(1001);
        vector<int> cycleEdge(2,-1);
        for(auto x: edges)
        {
            dsu->Union(x[0],x[1]);
            if(dsu->hasCycle)
            {
                cycleEdge[0]=x[0];
                cycleEdge[1]=x[1];
                break;
            }
        }
        return cycleEdge;
    }
};
