int firstOcc(int arr[], int n,int x)
{
    int ansIndx=-1;
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==x)
        {
            ansIndx=mid;
            h=mid-1;
        }
        else if(arr[mid]>x)
            h=mid-1;
        else
            l=mid+1;
    }
    return ansIndx;
}

int lastOcc(int arr[], int n,int x)
{
    int ansIndx=-1;
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==x)
        {
            ansIndx=mid;
            l=mid+1;
        }
        else if(arr[mid]>x)
            h=mid-1;
        else
            l=mid+1;
    }
    return ansIndx;
}
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    int first=firstOcc(arr,n,x);
    if(first!=-1)
    {
        ans[0]=first;
        if(first==n-1)
            ans[1]=n-1;
        else if(arr[first+1]!=x)
            ans[1]=first;
        else if(arr[n-1]==x)
            ans[1]=n-1;
        else
        {
            int last=lastOcc(arr,n,x);
            ans[1]=last;
        }
    }
    return ans;
}
