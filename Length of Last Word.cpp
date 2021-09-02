class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        if(n==1)
            return s[0]==' '?0:1;
        int h=n-1;
        int l;
        while(h>=0 && s[h]==' ')
            h--;
        if(h==-1)
            return 0;
        l=h;
        while(l>=0 && s[l]!=' ')
            l--;
        return h-l;
    }
};
