class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int qunt=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            qunt+=costs[i];
            if(qunt<=coins)
                count++;
            else
                break;
        }
        return count;
    }
};
