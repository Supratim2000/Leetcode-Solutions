class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size()==0)
            return;
        int i = m-1;
        int j = n-1;
        int x = m+n-1;
        while(j!=-1 && i!=-1)
        {
            if(nums2[j]>nums1[i])
                nums1[x--]=nums2[j--];
            else if(nums2[j]<nums1[i])
                nums1[x--]=nums1[i--];
            else
                nums1[x--] = nums2[j--];
        }
        
        if(i==-1)
        {
            for(int t=j;t>=0;t--)
                nums1[t]=nums2[t];
        }
    }
};
