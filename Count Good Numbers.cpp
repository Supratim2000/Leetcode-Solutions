class Solution {
public:
    int power(long long x, long long y, int p=1000000007)
    {
        int res=1;
        x=x%p;
        if(x==0)
            return 0;
        while(y>0)
        {
            if (y&1)
                res=(res*x)%p;
            y=y>>1;
            x=(x*x)%p;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        int mod=1000000007;
        long long countOfFive=(n+1)/2LL;
        long long countOfFour=n-countOfFive;
        long long fivePowered=power(5LL,countOfFive)%mod;
        long long fourPowered=power(4LL,countOfFour)%mod;
        return (int)(((fivePowered%mod)*(fourPowered%mod))%mod);
    }
};
