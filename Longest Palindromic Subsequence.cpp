//Memoization
class Solution {
public:
    int longestPalLen(string& s, vector<vector<int>>& dp, int i, int j) {
        if(i==j) {
            return dp[i][j]=1;
        }
        if(i>j) {
            return dp[i][j]=0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        if(s[i]==s[j]) {
            return dp[i][j]=2+longestPalLen(s,dp,i+1, j-1);
        } else {
            return dp[i][j]=max(longestPalLen(s,dp,i+1, j),longestPalLen(s,dp,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        longestPalLen(s,dp,0,n-1);
        return dp[0][n-1];
    }
};

//Tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) {
                    dp[i][j]=1;
                }
                else if(i>j) {
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<n-1;i++) {
            int x=0;
            int y=i+1;
            for(int j=i;j<n-1;j++) {
                if(s[x]==s[y]) {
                    dp[x][y]=2+dp[x+1][y-1];
                } else {
                    dp[x][y]=max(dp[x+1][y],dp[x][y-1]);
                }
                x++;
                y++;
            }
        }

        return dp[0][n-1];
    }
};
