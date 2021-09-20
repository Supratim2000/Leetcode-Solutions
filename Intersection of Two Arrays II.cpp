//Approach 1(Using hashing)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
            freq[nums1[i]]++;
        for(int i=0;i<m;i++)
        {
            if(freq.find(nums2[i])!=freq.end() && freq[nums2[i]]>0)
            {
                ans.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        return ans;
    }
};

//Approach 2(Using Sorting and two pointer)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};
