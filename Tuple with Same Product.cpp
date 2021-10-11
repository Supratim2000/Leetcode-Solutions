class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                freq[nums[i]*nums[j]]++;
        for(auto x: freq)
            count+=4*x.second*(x.second-1);
        return count;
    }
};
