class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxAns=INT_MIN;
        int ans;
        vector<vector<bool>> isConnected(n,vector<bool>(n,false));
        vector<int> deg(n,0);
        for(int i=0;i<roads.size();i++)
        {
            isConnected[roads[i][0]][roads[i][1]]=true;
            isConnected[roads[i][1]][roads[i][0]]=true;
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=deg[i]+deg[j];
                if(isConnected[i][j])
                    ans--;
                maxAns=max(ans,maxAns);
            }
        }

        return maxAns; 
    }
};
