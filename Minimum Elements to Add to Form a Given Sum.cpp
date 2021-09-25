class Solution {
public:  
    long long add(vector<int>& arr)
    {
        long long sum=0;
        for(int i=0;i<arr.size();i++)
            sum+=arr[i];
        return sum;
    }
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=add(nums);
        long long diff=abs(sum-goal);
        return (diff+limit-1)/limit;
    }
};
