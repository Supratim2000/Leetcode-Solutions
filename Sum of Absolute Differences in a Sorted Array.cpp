//Time Complexity:- O(N)
//Space Complexity:- O(N)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int last=nums[n-1];
        vector<int> ans(n,0);
        vector<int> pf(n,0);
        pf[0]=nums[0];
        for(int i=1;i<n;i++)
            pf[i]=nums[i]+pf[i-1];
        for(int i=n-2;i>=1;i--)
        {
            ans[i]=(i*nums[i])-pf[i-1]+last-((n-i-1)*nums[i]);
            last=last+nums[i];
        }
        ans[0]=last-((n-1)*nums[0]);
        ans[n-1]=((n-1)*nums[n-1])-pf[n-2];
        return ans;
    }
};

//Time Complexity:- O(N)
//Space Complexity:- O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int sum=0;
        int sumTillIndex=0;
        for(auto x: nums)
            sum+=x;
        for(int i=0;i<n;i++)
        {
            sumTillIndex+=nums[i];
            ans[i]=((i+1)*nums[i])-sumTillIndex+(sum-sumTillIndex)-((n-i-1)*nums[i]);
        }
        return ans;
    }
};
