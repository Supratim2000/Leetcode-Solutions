class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int count=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        for(int i=1;i<n-1;i++)
            if(st.find(nums[i]-diff)!=st.end() && st.find(nums[i]+diff)!=st.end())
                count++;
        return count;
    }
};
