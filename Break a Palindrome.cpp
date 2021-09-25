class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)
            return "";
        int i=0;
        for(;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                break;
            }
        }
        if(i==n/2)
            palindrome[n-1]='b';
        return palindrome;
    }
};
