class Solution {
public:
    bool isDigit(char c) {
        if(c>='0' && c<='9')
            return true;
        return false;
    }

    char flipCase(char c) {
        if(c>='a' && c<='z')
            return (char)(c-32);
        else
            return (char)(c+32);
    }

    void generate(string s, vector<string>& ans, string cont, int i) {
        if(i==s.size())
        {
            ans.push_back(cont);
            return;
        }
        if(isDigit(s[i])) {
            cont.push_back(s[i]);
            generate(s,ans,cont,i+1);
        } else {
            cont.push_back(s[i]);
            generate(s,ans,cont,i+1);
            cont.pop_back();
            cont.push_back(flipCase(s[i]));
            generate(s,ans,cont,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        generate(s,ans,"",0);
        return ans;
    }
};
