class Solution {
public:
    bool isVowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        int n=s.length();
        while(j<n)
        {
            if(isVowel(s[j]))
                count++;
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                ans=max(count,ans);
                if(isVowel(s[i]))
                    count--;
                i++;
                j++;
            }
        }
        return ans;
    }
};
