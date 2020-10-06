class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        unsigned long long low = 1;
        unsigned long long high = n;
        unsigned long long sum,mid,ans;
        while(low<=high)
        {
            mid = low + (high - low) / 2;
            sum=mid*(mid+1)/2;
            if(n >= sum)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return (int)ans;
    }
};
