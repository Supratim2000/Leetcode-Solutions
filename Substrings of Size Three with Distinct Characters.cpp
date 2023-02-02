class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int count=0;
        unordered_map<char,int> freq;
        while(j<n)
        {
            freq[s[j]]++;
            if(j-i+1==3)
            {
                if(freq.size()==3)
                    count++;
                freq[s[i]]--;
                if(freq[s[i]]==0)
                    freq.erase(s[i]);
                i++;
            }
            j++;
        }
        return count;
    }
};
