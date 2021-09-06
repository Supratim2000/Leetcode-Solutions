//Recursive solution(Unoptimised)
class Solution {
public:
    
    bool helper(string s,string t,int i,int j,int n1,int n2)
    {
        if(i==n1)
            return true;
        else if(j==n2)
            return false;
        else
        {
            if(s[i]==t[j])
                return helper(s,t,i+1,j+1,n1,n2);
            else
                return helper(s,t,i,j+1,n1,n2);
        }
    }
    
    bool isSubsequence(string s, string t) {
        return helper(s,t,0,0,s.size(),t.size());
    }
};

//Memoized solution
class Solution {
public:
    bool helper(string s,string t,int i,int j,int n1,int n2,vector<vector<int>>& dp)
    {
        if(i==n1)
            return true;
        else if(j==n2)
            return false;
        else
        {
            if(s[i]==t[j])
            {
                if(dp[i+1][j+1]==-1)
                    dp[i+1][j+1]=helper(s,t,i+1,j+1,n1,n2,dp);
                return dp[i+1][j+1];
            }
            else
            {
                if(dp[i][j+1]==-1)
                    dp[i][j+1]=helper(s,t,i,j+1,n1,n2,dp);
                return dp[i][j+1];
            }
        }
    }
    
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,0,0,s.size(),t.size(),dp);
    }
};
