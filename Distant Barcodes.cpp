class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){return (b.first<a.first);}
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        vector<int> ans(n);
        unordered_map<int,int> freq;
        vector<pair<int,int>> vec;
        for(auto x: barcodes)
            freq[x]++;
        for(auto x: freq)
            vec.push_back({x.second,x.first});
        sort(vec.begin(),vec.end(),comp);
        int i=0;
        int j=0;
        while(i<n)
        {
            ans[i]=vec[j].second;
            vec[j].first--;
            if(vec[j].first==0)
                j++;
            i+=2;
        }
        i=1;
        while(i<n)
        {
            ans[i]=vec[j].second;
            vec[j].first--;
            if(vec[j].first==0)
                j++;
            i+=2;
        }
        return ans;
    }
};
