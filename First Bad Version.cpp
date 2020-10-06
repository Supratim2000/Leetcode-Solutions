// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1))
            return 1;
        long long low=1;
        long long high=n;
        long long ans;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(!isBadVersion(mid))
            {
                ans=mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ++ans;
    }
};
