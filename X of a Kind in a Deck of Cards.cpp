class Solution {
public:
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int n=deck.size();
        int gcd_arr=0;
        unordered_map<int,int> freq;
        for(auto x: deck)
            freq[x]++;
        for(auto x: freq)
            gcd_arr=gcd(gcd_arr,x.second);
        return gcd_arr>=2;
    }
};
