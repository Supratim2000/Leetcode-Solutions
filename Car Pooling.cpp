class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int capCurPoint[1001]={0};
        for(auto x: trips)
        {
            for(int i=x[1];i<x[2];i++)
            {
                capCurPoint[i]+=x[0];
                if(capCurPoint[i]>capacity)
                    return false;
            }
        }
        return true;
    }
};
