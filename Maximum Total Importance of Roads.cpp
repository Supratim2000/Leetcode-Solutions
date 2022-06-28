class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int count=1;
        long long sum=0;
        vector<long long> deg(n,0);
        vector<pair<long long,long long>> p(n);
        for(auto x: roads)
        {
            deg[x[0]]++;
            deg[x[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            p[i].first=deg[i];
            p[i].second=i;
        }
        sort(p.begin(),p.end());
        for(auto x: p)
            deg[x.second]=count++;
        for(auto x:roads)
            sum+=deg[x[0]]+deg[x[1]];
        return sum;
    }
};
