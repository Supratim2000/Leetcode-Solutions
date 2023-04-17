class Solution {
public:
    void genSubsets(vector<int> nums, int i, vector<int> ds, vector<vector<int>>& ans) {
        if(i<0)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        genSubsets(nums,i-1,ds,ans);
        ds.pop_back();
        genSubsets(nums,i-1,ds,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=nums.size();
        genSubsets(nums,n-1,ds,ans);
        return ans;
    }
};
