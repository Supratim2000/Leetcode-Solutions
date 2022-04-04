class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> mp;
        int n=text.size();
        string word="";
        string ans="";
        int curLen=0;
        for(int i=0;i<n;i++)
        {
            if(text[i]==' ')
            {
                mp[curLen].push_back(word);
                word="";
                curLen=0;
            }
            else
            {
                word+=text[i];
                curLen++;
            }
        }
        mp[curLen].push_back(word);
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            for(auto x: it->second)
            {
                if(x[0]>='A' && x[0]<='Z')
                    x[0]=x[0]+32;
                ans+=x;
                ans+=" ";
            }
        }
        ans.pop_back();
        ans[0]=ans[0]-32;
        return ans;
    }
};
