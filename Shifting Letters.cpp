class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
                shifts[i]=(shifts[i]+shifts[i+1])%26;
            s[i]=(((s[i]-97)+shifts[i])%26)+97;   
        }
        return s;
    }
};
