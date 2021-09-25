class Solution {
public:
    int maximum(vector<int>& nums,int& n)
    {
        int mx=INT_MIN;
        for(auto x: nums)
            mx=max(mx,x);
        return mx;
    }
    
    long long divSum(vector<int>& nums,int& n,int d)
    {
        long long add=0;
        for(auto x: nums)
            add+=((x+d-1)/d);
        return add;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=INT_MIN;
        int n=nums.size();
        int l=1;
        int h=maximum(nums,n)+1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            long long res=divSum(nums,n,mid);
            if(res<=threshold)
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
