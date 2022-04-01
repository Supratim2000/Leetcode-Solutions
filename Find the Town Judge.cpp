class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> netDeg(n+1,0);
        for(auto x: trust)
        {
            netDeg[x[0]]--;
            netDeg[x[1]]++;
        }
        for(int i=1;i<=n;i++)
            if(netDeg[i]==n-1)
                return i;
        return -1;
    }
};
