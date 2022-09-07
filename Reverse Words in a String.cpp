class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stack<char> st;
        string res="";
        bool prevSpace=false;
        int sp=-1;
        int ep=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                if(sp==-1)
                    sp=i;
                ep=i;
            }
        }
        for(int i=ep;i>=sp;i--)
        {
            if(s[i]==' ')
            {
                while(!st.empty())
                {
                    res+=st.top();
                    st.pop();
                }
                if(!prevSpace)
                    res+=' ';
                prevSpace=true;
            }
            else
            {
                prevSpace=false;
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
