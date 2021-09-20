class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        unordered_set<int> pres;
        unordered_set<int> doneInNums2;
        for(int i=0;i<n;i++)
            pres.insert(nums1[i]);
        for(int i=0;i<m;i++)
        {
            if(pres.find(nums2[i])!=pres.end() && doneInNums2.find(nums2[i])==doneInNums2.end())
            {
                ans.push_back(nums2[i]);
                doneInNums2.insert(nums2[i]);
            }
        }
        return ans;
    }
};
