class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j--;
        }
        if(j+2==i)
            ans.pop_back();
        return ans;
    }
};
