class Solution {
public:
    void perm(vector<int>& nums, int n, int i, vector<vector<int>>& ans)
    {
        if(i==n)
            ans.push_back(nums);
        else
        {
            for(int j=i;j<n;j++)
            {
                swap(nums[i],nums[j]);
                perm(nums,n,i+1,ans);
                swap(nums[i],nums[j]);
            }   
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,nums.size(),0,ans);
        return ans;
    }
};
