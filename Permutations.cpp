//Using extra space
class Solution {
public:
    void permutation(vector<int>& arr, vector<vector<int>>& ans, unordered_set<int> vis, vector<int> ds, int n) {
        if(ds.size()==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(vis.find(i)==vis.end())
            {
                ds.push_back(arr[i]);
                vis.insert(i);
                permutation(arr,ans,vis,ds,n);
                ds.pop_back();
                vis.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> vis;
        vector<int> ds;
        int n=nums.size();
        permutation(nums,ans,vis,ds,n);
        return ans;
    }
};


//Without using extra space
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
