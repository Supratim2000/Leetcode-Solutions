class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr[1]>arr[0] && arr[2]<arr[1])
            return 1;
        unsigned long long low = 0;
        unsigned long long high = arr.size()-1;
        unsigned long long mid,ans;
        while(low<=high)
        {
            mid = low + (high - low)/2;
            if(arr[mid-1]<arr[mid])
            {
                ans=mid;
                low= mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
            
    }
};
