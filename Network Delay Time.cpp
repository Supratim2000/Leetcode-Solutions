class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=INT_MIN;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        for(vector<int> x: times)
            adj[x[0]].push_back({x[1],x[2]});
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            pair<int,int> cur=pq.top();
            pq.pop();
            for(auto x: adj[cur.second])
            {
                if(dist[x.first]>dist[cur.second]+x.second)
                {
                    dist[x.first]=dist[cur.second]+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        for(int i=1;i<=n;i++)
            ans=max(ans,dist[i]);
        return ans==INT_MAX?-1:ans;
    }
};
