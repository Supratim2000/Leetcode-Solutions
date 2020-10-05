class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<bool> mount;
        mount.push_back(true);
        for(int i=1;i<arr.size();i++)
            arr[i-1]<arr[i] ? mount.push_back(true) : mount.push_back(false);
        
        long long low = 0;
        long long high = mount.size()-1;
        long long ans;
        
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(mount[mid]==true) {
                ans=mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;                
            
    }
};
