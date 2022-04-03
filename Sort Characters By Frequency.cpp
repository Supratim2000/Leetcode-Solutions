class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        vector<vector<char>> bucket(n+1);
        string st="";
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++)
            freq[s[i]]++;
        for(auto x: freq)
        {
            bucket[x.second].push_back(x.first);
        }
        for(int i=n;i>=0;i--)
        {
            if(bucket[i].size()>0)
            {
                for(auto x: bucket[i])
                {
                    for(int j=0;j<i;j++)
                        st+=x;
                }
            }
        }
        return st;
    }
};
