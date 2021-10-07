class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        unordered_map<string,vector<string>> mp;
        for(auto str: strs)
        {
            string sorted=str;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<string> temp;
            for(auto x: it->second)
                temp.push_back(x);
            group.push_back(temp);
        }
        return group;
    }
};
