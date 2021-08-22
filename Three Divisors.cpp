class Solution {
public:
    bool isPrime(int n)
    {
        if (n<=1)
            return false;
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                return false;
        return true;
    }
    
    bool isSqure(int n)
    {
        return ceil((double)sqrt(n)) == floor((double)sqrt(n));
    }
    
    bool isThree(int n) {
        return isSqure(n) && isPrime((int)sqrt(n));
    }
};
