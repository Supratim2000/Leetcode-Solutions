class DSU {
public:
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
    
    bool Union(int u, int v)
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
            return true;
        }
        return false;
    }    
};
class Node {
public:
    int u;
    int v;
    int wt;
    Node(int u, int v, int wt) {
        this->v=v;
        this->u=u;
        this->wt=wt;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU* dsu=new DSU(1001);
        int cost=0;
        int n=points.size();
        vector<Node> wtList;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                wtList.push_back(Node(i,j,dist(points[i][0],points[i][1],points[j][0],points[j][1])));
        sort(wtList.begin(),wtList.end(),comp);
        for(auto x: wtList)
            if(dsu->Union(x.u, x.v))
                cost+=x.wt;
        return cost;
    }
    int dist(int x1,int y1,int x2,int y2) {return abs(x1-x2)+abs(y1-y2);}
    static bool comp(Node a, Node b) {return a.wt<b.wt;}
};
