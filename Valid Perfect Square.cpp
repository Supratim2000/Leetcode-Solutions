class Solution {
public:
    
    bool binarySearch(int n) {
        long low = 0;
        long high = n;
        while(low<=high)
        {
            long mid = (high+low)/2;
            if(mid*mid == n)
                    return true;
            else if(mid*mid < n)
                low = mid+1;
            else
                high = mid - 1;
        }
        return false;
    }
    
    bool isPerfectSquare(int num) {
        return binarySearch(num);
    }
};
