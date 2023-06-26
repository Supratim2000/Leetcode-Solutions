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
        return parent[v]=find(parent[v]);
    }
    
    void _union(int u, int v)
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
    }    
};

class Solution {
public:
    long long numNodeToTotalConnections(int n) {
        //For avoiding overflow
        if(n%2==0)
        {
            long long x=n/2;
            long long y=x*(n-1);
            return y;
        }
        else
        {
            long long x=(n-1)/2;
            long long y=x*n;
            return y;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long numOfConnectionsIfAllNodesConnected=numNodeToTotalConnections(n);
        long long numOfConnectionsIfIndividualcomponentsAreConnected=0;
        unordered_map<long long,long long> mp;
        DSU* dsu=new DSU(n);
        for(int i=0;i<edges.size();i++)
            dsu->_union(edges[i][0],edges[i][1]);

        for(int i=0;i<n;i++)
            mp[dsu->find(i)]++;

        for(auto it=mp.begin();it!=mp.end();it++)
            numOfConnectionsIfIndividualcomponentsAreConnected+=numNodeToTotalConnections(it->second);

        return numOfConnectionsIfAllNodesConnected-numOfConnectionsIfIndividualcomponentsAreConnected;
    }
};
