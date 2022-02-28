//Memoization
class Solution {
public:
    int maxSum(vector<int> &arr, int j, vector<int>& dp)
    {
        if(j<0)
            return 0;
        if(j==0)
            return arr[j];
        if(dp[j]!=-1)
            return dp[j];
        int taken=maxSum(arr,j-2,dp)+arr[j];
        int notTaken=maxSum(arr,j-1,dp);
        return dp[j]=max(taken,notTaken);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return maxSum(nums,n-1,dp);
    }
};

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int taken=dp[i-2]+nums[i];
            int notTaken=dp[i-1];
            dp[i]=max(taken,notTaken);
        }
        return dp[n-1];
    }
};

//Space optimization
