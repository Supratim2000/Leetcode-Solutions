class Solution {
public:
    int countPrimes(int n)
    {
        if(n==0 || n==1)
            return 0;
        int count=0;
        int arr[n];
        arr[0] = 0; //0->not prime
        arr[1] = 0; //1->not prime
        for (int i = 2; i < n; i++)
            arr[i] = 1; //all prime except 0 and 1.
        for (int i = 2; i * i < n; i++)
        {
            if (arr[i] == 1)
            {
                for (int j = 2; i * j < n; j++)
                    arr[i * j] = 0;
            }
        }
        for(int i=2;i<n;i++)
            if(arr[i]==1)
                count++;
        return count;
    }
};
