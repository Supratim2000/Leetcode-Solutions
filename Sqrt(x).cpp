class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int low = 0;
        int high = x;
        long long mid;
        int ans;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(mid*mid <= x) {
                ans=mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
