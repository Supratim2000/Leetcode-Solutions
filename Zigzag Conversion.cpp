class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1)
            return s;
        else if(numRows==2)
        {
            string ev="";
            string od="";
            for(int i=0;i<n;i++)
                i&1?od+=s[i]:ev+=s[i];
            return ev+od;
        }
        else
        {
            string ans="";
            int x=0;
            int row=0;
            vector<string> mp(numRows,"");
            for(int i=0;i<n;i++)
            {
                if(row%2==0)
                    mp[x++].push_back(s[i]);
                else
                {
                    if(x==numRows)
                        x-=2;
                    mp[x--].push_back(s[i]);
                }
                if(x==numRows || x==0)
                    row++;
            }
            for(auto st: mp)
                ans+=st;
            return ans;
        }
    }
};
