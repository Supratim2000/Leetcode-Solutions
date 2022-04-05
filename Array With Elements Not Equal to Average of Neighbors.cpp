//Method 1
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
            ans.push_back(nums[i++]);
            ans.push_back(nums[j--]);
        }
        if(j+2==i)
            ans.pop_back();
        return ans;
    }
};

//Method 2
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n,0);
        int j=0;
        for(int i=0;i<n;i+=2)
            ans[i]=nums[j++];
        for(int i=1;i<n;i+=2)
            ans[i]=nums[j++];
        return ans;
    }
};
