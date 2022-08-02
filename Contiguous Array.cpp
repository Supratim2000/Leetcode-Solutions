class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxSubArray=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp.insert({0,-1});
        for(int i=0;i<n;i++)
        {
            nums.at(i)==1?sum++:sum--;
            if(mp.find(sum)==mp.end())
                mp.insert({sum,i});
            else
                maxSubArray=max(i-mp[sum],maxSubArray);
        }
        return maxSubArray;
    }
};
