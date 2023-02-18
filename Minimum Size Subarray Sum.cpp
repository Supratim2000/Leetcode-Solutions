class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=0;
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            sum+=nums.at(j);
            while(sum>=target)
            {
                ans=min(j-i+1,ans);
                sum=sum-nums.at(i);
                i++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
