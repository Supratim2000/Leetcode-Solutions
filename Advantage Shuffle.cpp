class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        multiset<int> aset;
        for(int x: nums1)
            aset.insert(x);
        for(int x: nums2)
        {
            auto justUp=aset.upper_bound(x);
            if(justUp==aset.end())
                justUp=aset.begin();
            ans.push_back(*justUp);
            aset.erase(justUp);
        }
        return ans;
    }
};
