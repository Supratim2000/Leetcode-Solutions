#include <bits/stdc++.h> 

//Space optimized DP solution
vector<bool> generateIfSubsetSumPossible(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,false);
    vector<bool> cur(k+1,false);
    prev[0]=true;
    if(arr[0]<=k)
        prev[arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        cur[0]=true;
        for(int j=1;j<=k;j++)
        {
            bool notTake=prev[j];
            bool take=false;
            if(j-arr[i]>=0)           
                take=prev[j-arr[i]];
            cur[j]= take || notTake;
        }
        for(int x=0;x<=k;x++)
            prev[x]=cur[x];
    }
    return prev;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int minDiff=INT_MAX;
	int totalSum=0;
	for(int i=0;i<n;i++)
		totalSum+=arr[i];
	vector<bool> possibleSubsetSums=generateIfSubsetSumPossible(n, totalSum, arr);
	for(int i=0;i<=totalSum;i++)
        if(possibleSubsetSums[i])
            minDiff=min(abs(2*i-totalSum), minDiff);
    return minDiff;
}
