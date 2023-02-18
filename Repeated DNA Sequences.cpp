class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_map<string,int> freq;
        string running;
        vector<string> ans;
        int i=0;
        while(i+10<=n)
        {
            running=s.substr(i,10);
            freq[running]++;
            i++;
        }
        for(auto x: freq)
            if(x.second>1)
                ans.push_back(x.first);
        return ans;
    }
};
