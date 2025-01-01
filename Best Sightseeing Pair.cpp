class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxScore = INT_MIN;
        int suffixMax = values.at(n-1) - n + 1;
        for(int i=n-2;i>=0;i--) {
            maxScore = max(values.at(i) + i + suffixMax, maxScore);
            suffixMax = max(values.at(i) - i, suffixMax);
        }
        return maxScore;
    }
};
