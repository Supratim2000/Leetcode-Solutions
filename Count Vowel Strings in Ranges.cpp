class Solution {
public:
    static bool isVowelCheck(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> ans;
        vector<int> prefix(n,0);
        prefix[0]=(isVowelCheck(words[0][0]) && isVowelCheck(words[0][words[0].size()-1]))?1:0;
        for(int i=1;i<n;i++) {
                prefix[i]=prefix[i-1]+(isVowelCheck(words[i][0]) && isVowelCheck(words[i][words[i].size()-1]));
        }
        for(int i=0;i<m;i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start==0) {
                ans.push_back(prefix[end]);    
            } else {
                ans.push_back(prefix[end]-prefix[start-1]);
            }            
        }
        return ans;
    }
};
