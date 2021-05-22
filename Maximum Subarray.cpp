class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int freq=0;
        if(n==0)
            return nums.at(0);
        int max_elmt=INT_MIN;
        int sum=0;
        int maxSum=INT_MIN;
        
        for(auto x:nums)
        {
            sum+=x;
            max_elmt=max(x,max_elmt);
            if(sum<0)
            {
                sum=0;
                freq++;
            }
            if(maxSum<sum)
                maxSum=sum;
        }
        if(freq==n)
            return max_elmt;
        return maxSum;
    }
};
