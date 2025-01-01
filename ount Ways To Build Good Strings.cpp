class Solution {
public:
    long long calculate(long long curVal, int low, int high, int zero, int one, vector<long long>& dp) {
        if(curVal > high) {
            return 0;
        }
        if(dp[curVal] != -1) {
            return dp[curVal];
        }

        long long zeroAddCount = calculate(curVal+zero, low, high, zero, one, dp);
        zeroAddCount = (zeroAddCount % 1000000007);
        long long oneAddCount = calculate(curVal+one, low, high, zero, one, dp);
        oneAddCount = (oneAddCount % 1000000007);
        long long totalCount = ((zeroAddCount + oneAddCount) % 1000000007);
        if(curVal>=low && curVal<=high) {
            return dp[curVal] = totalCount + 1;
        } else {
            return dp[curVal] = totalCount;
        }
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1,-1);
        return calculate(0,low,high,zero,one,dp);
    }
};
