class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        vector<int> setBitCount(32,0);
        int ans=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<32;j++) {
                if((1<<j)&candidates[i]) {
                    setBitCount[j]++;
                }
            }
        }

        for(int i=0;i<32;i++) {
            ans=max(ans,setBitCount[i]);
        }

        return ans;
    }
};
