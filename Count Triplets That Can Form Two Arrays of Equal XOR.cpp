class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        int extraCountForZero=0;
        unordered_map<int,vector<int>> eindx;
        int x=arr[0];
        eindx[x].push_back(0);
        for(int i=1;i<n;i++)
        {
            x=x^arr[i];
            if(x==0)
                extraCountForZero+=i;
            eindx[x].push_back(i);
        }
        for(auto x: eindx)
            for(int i=x.second.size()-1;i>=0;i--)
                count+=i*x.second[i]-(i*(x.second[x.second.size()-i-1]+1));
        count+=extraCountForZero;
        return count;
    }
};
