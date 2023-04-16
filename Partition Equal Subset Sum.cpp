class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1,false);
        vector<bool> cur(k+1,false);
        prev[0]=true;
        if(arr[0]<=k)
            prev[arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            cur[0]=true;
            for(int j=1;j<=k;j++)
            {
                bool notTake=prev[j];
                bool take=false;
                if(j-arr[i]>=0)           
                    take=prev[j-arr[i]];
                cur[j]= take || notTake;
            }
            for(int x=0;x<=k;x++)
                prev[x]=cur[x];
        }
        return prev[k];    
    }
    int sumOfArray(vector<int>& nums) {
        int sum=0;
        for(auto x: nums)
            sum+=x;
        return sum;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=sumOfArray(nums);
        int target=totalSum/2;
        return totalSum&1?false:subsetSumToK(n,target,nums);    
    }
};
