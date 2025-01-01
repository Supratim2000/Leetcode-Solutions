class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> count(2,0);
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                count[0]++;
            } else {
                count[1]++;
            }
        }
        int maxScore=0;
        int numZ=0;
        int numO=count[1];
        for(int i=0;i<n-1;i++) {
            if(s[i]=='0') {
                numZ++;
            } else {
                numO--;
            }
            maxScore=max(numZ+numO, maxScore);
        }
        return maxScore;
    }
};
