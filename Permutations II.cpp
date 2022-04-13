class Solution {
public:
    void permute(vector<int>& nums, int n, int i, vector<vector<int>>& ans)
    {
        if(i==n)
            ans.push_back(nums);
        else
        {
            unordered_set<int> vis;
            for(int j=i;j<n;j++)
            {
                if(vis.find(nums[j])!=vis.end())
                    continue;
                vis.insert(nums[j]);
                swap(nums[i],nums[j]);
                permute(nums,n,i+1,ans);
                swap(nums[i],nums[j]);
            }   
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums,nums.size(),0,ans);
        return ans;
    }
};
