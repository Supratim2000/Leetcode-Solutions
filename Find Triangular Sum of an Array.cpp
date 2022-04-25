//Iterative
//Time complexity:- O(n^2)
//Space complexity:- O(n) (Due to recursion stack)
class Solution {
public:
    int rec(vector<int> nums, int n)
    {
        if(n==1) return nums.at(0);
        vector<int> smallAns(n-1);
        for(int i=0;i<n-1;i++)
            smallAns[i]=(nums[i]+nums[i+1])%10;
        return rec(smallAns,n-1);
    }
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        return rec(nums,n);
    }
};

//Iterative
//Time complexity:- O(n^2)
//Space complexity:- O(1)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                nums[j]=(nums[j]+nums[j+1])%10;
        return nums.at(0);
    }
};
