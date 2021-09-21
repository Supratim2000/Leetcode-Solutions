class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int back=nums[n-1];
        int temp;
        vector<int> ans(n,1);
        ans[0]=nums[0];
        for(int i=1;i<n;i++)
            ans[i]=nums[i]*ans[i-1];
        temp=ans[n-2];
        for(int i=n-2;i>=1;i--)
        {
            ans[i]=ans[i-1]*back;
            back=back*nums[i];
        }
        ans[0]=back;
        ans[n-1]=temp;
        return ans;
    }
};
