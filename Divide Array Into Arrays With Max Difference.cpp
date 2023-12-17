class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        while(i+2<n) {
            if(nums[i+1]-nums[i]<=k && nums[i+2]-nums[i+1]<=k && nums[i+2]-nums[i]<=k) {
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            } else {
                break;
            }
            
            i+=3;
        }
        if(ans.size()!=n/3) {
            ans.clear();
        }
        return ans;
    }
};
