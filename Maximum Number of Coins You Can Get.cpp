class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int t=n/3;
        int index=n-2;
        for(int i=0;i<t;i++,index-=2)
            sum+=piles[index];
        return sum;
    }
};
