class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxScore=0;
        int numZ=0;
        int numO=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                numO++;
            }
        }
        for(int i=0;i<n-1;i++) {
            s[i]=='0'?numZ++:numO--;
            maxScore=max(numZ+numO, maxScore);
        }
        return maxScore;
    }
};
