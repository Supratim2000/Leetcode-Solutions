class Solution {
public:
    bool partition(vector<int>& arr, int i, int n, vector<int>& dp) {
        if(i==n)
            return true;
        if(dp[i]!=-1)
            return dp[i];
        if(i+1<n && arr[i+1]==arr[i]) {
            if(partition(arr,i+2,n,dp))
                return dp[i]=true;
        }
        if(i+1<n && i+2<n && arr[i+1]==arr[i] && arr[i+2]==arr[i]) {
            if(partition(arr,i+3,n,dp))
                return dp[i]=true;
        }
        if(i+1<n && i+2<n && arr[i+1]==arr[i]+1 && arr[i+2]==arr[i]+2) {
            if(partition(arr,i+3,n,dp))
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        // -1 -> Not yet solved
        // 0 -> no valid partitions possible till i to n-1
        // 1 -> valid partitions possible till i to n-1
        vector<int> dp(n,-1);
        partition(nums,0,nums.size(),dp);
        return dp[0];
    }
};
