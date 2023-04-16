#include <bits/stdc++.h> 

//Space optimised DP solution
void generateIfSubsetSumPossible(int n, int k, int& minDiff, vector<int> &arr) {
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
    for(int i=0;i<=k;i++)
        if(prev[i])
            minDiff=min(abs(2*i-k), minDiff);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int minDiff=INT_MAX;
	int totalSum=0;
	for(int i=0;i<n;i++)
		totalSum+=arr[i];
	generateIfSubsetSumPossible(n, totalSum, minDiff, arr);
	return minDiff;
}
