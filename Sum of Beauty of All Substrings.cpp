class Solution {
public:
    int beautySum(string s) {
        int beauty=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int mn=INT_MAX;
                int mx=INT_MIN;
                for(int i=0;i<26;i++)
                {
                    if(freq[i]<mn && freq[i])
                        mn=freq[i];
                    if(freq[i]>mx && freq[i])
                        mx=freq[i];
                    if(mn== INT_MAX || mx==INT_MIN)
                        continue;
                }
                beauty+=(mx-mn);
            }
        }
        return beauty;
    }
};
