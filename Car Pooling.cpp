//Brute-force
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

//Using Map
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> netPas;
        for(auto x: trips)
        {
            netPas[x[1]]+=x[0];
            netPas[x[2]]-=x[0];
        }
        for(auto x: netPas)
        {
            capacity-=x.second;
            if(capacity<0)
                return false;
        }
        return true;
    }
};

//Using Sorting
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> timeline;
        for(auto x: trips)
        {
            vector<int> a(3,0);
            vector<int> b(3,0);
            a[0]=x[1]; a[1]=1; a[2]=x[0];
            b[0]=x[2]; b[1]=0; b[2]=x[0];
            timeline.push_back(a);
            timeline.push_back(b);
        }
        sort(timeline.begin(),timeline.end());
        int cur=0;
        for(auto x: timeline)
        {
            x[1]==1?capacity-=x[2]:capacity+=x[2];
            if(capacity<0)
                return false;
        }
        return true;
    }
};
