class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long minFuel=0;
        int n=roads.size()+1;
        vector<int> adj[n];
        vector<int> deg(n,0);
        vector<int> people(n,1);
        queue<int> q;
        for(auto x: roads)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
            deg[x[1]]++;
        }

        for(int i=1;i<n;i++)
            if(deg[i]==1)
                q.push(i);

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            if(curNode==0)
                break;
            minFuel+=ceil(((people[curNode]*1.0)/seats));
            for(auto adjNode: adj[curNode])
            {
                people[adjNode]+=people[curNode];
                deg[adjNode]--;
                if(deg[adjNode]==1 && adjNode!=0)
                    q.push(adjNode);
            }
        }

        return minFuel;
    }
};
