class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string smallAns=countAndSay(n-1);
        string ans="";
        int i=0;
        int count=0;
        char f=smallAns[0];
        while(i<smallAns.size())
        {
            if(smallAns[i]==f)
            {
                count++;
                i++;
            }
            else
            {
                ans+=to_string(count*10+(f-'0'));
                count=0;
                f=smallAns[i];
            }
        }
        if(count!=0)
            ans+=to_string(count*10+(f-'0'));
        return ans;
    }
};
