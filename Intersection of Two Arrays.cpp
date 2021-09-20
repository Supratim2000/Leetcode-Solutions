//Approach 1(Using hashing)
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

//Approach 2(Using Sorting and binary search)
class Solution {
public:
    bool binSrc(vector<int>& arr,int key,int low,int high)
    {
        while(low<=high)
        {
            int mid=low+((high-low)/2);
            if(arr[mid]==key)
                return true;
            else if(key<arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        unordered_set<int> doneInNums2;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<m;i++)
        {
            if(doneInNums2.find(nums2[i])==doneInNums2.end() && binSrc(nums1,nums2[i],0,n-1))
            {
                ans.push_back(nums2[i]);
                doneInNums2.insert(nums2[i]);
            }
        }
        return ans;
    }
};

//Using Sorting and 2 pointer
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        unordered_set<int> ansWithoutDup;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            if(nums1[i]==nums2[j])
            {
                ansWithoutDup.insert(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        for(auto x: ansWithoutDup)
            ans.push_back(x);
        return ans;
    }
};
