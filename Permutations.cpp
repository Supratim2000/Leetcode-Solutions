class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1)
        {
            vector<vector<int>> ans;
            ans.push_back(nums);
            return ans;
        }
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            int erased=nums[i];
            vector<int> temp;
            for(int j=0;j<nums.size();j++)
                if(i!=j)
                    temp.push_back(nums[j]);
            vector<vector<int>> x=permute(temp);
            for(int k=0;k<x.size();k++)
            {
                x[k].insert(x[k].begin(),erased);
                res.push_back(x[k]);
            } 
        }
        return res;
    }
};
