class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int tempCount=1;
        for(int i=n-2;i>=0;i--,tempCount++)
            if(nums[i]!=nums[i+1])
                count+=tempCount;
        return count;
    }
};
