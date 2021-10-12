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
    
    void helper(string& digits,int l,unordered_map<char,string>& mp,vector<string>& ans,string cur)
    {
        if(digits.size())
        {
            if(cur.size()==digits.size())
                ans.push_back(cur);
            for(int i=0;i<mp[digits[l]].size();i++)
                helper(digits,l+1,mp,ans,cur+mp[digits[l]][i]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        generateMap(mp);
        vector<string> ans;
        helper(digits,0,mp,ans,"");
        return ans;
    }
};
