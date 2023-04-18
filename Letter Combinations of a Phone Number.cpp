class Solution {
public:
    void generateMap(unordered_map<char,string>& mp)
    {
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
    }

    void generateCombinations(string s, string ds, vector<string>& ans,unordered_map<char,string>& mp,int index) {
        if(s.size()==0)
            return;
        if(index==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<mp[s[index]].size();i++)
        {
            ds.push_back(mp[s[index]][i]);
            generateCombinations(s,ds,ans,mp,index+1);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        generateMap(mp);
        string ds;
        vector<string> ans;
        generateCombinations(digits,ds,ans,mp,0);
        return ans;
    }
};
