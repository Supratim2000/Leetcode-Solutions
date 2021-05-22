typedef long long ll;
class Solution {
public:
    int lowerBound(vector<int>& arr,int key)
    {
        int n=arr.size();
        int l=0,h=n-1;
        int ans=-1;
        int mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(arr.at(mid)==key)
            {
                ans=mid;
                h=mid-1;
            }
            else if(arr.at(mid)<key)
                l=mid+1;
            else
                h=mid-1;
        }
        return ans;
    }
        
    int upperBound(vector<int>& arr,int key)
    {
        int n=arr.size();
        int l=0,h=n-1;
        int ans=-1;
        int mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(arr.at(mid)==key)
            {
                ans=mid;
                l=mid+1;
            }
            else if(arr.at(mid)<key)
                l=mid+1;
            else
                h=mid-1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(lowerBound(nums,target));
    ans.push_back(upperBound(nums,target));
    return ans;
    }
};
