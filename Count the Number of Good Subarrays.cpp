class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int i=0;
        long long numOfPairs=0;
        long long ans=0;
        for(int j=0;j<n;j++)
        {
            freq[nums[j]]++;
            numOfPairs+=(freq[nums[j]]-1);
            while(i<j && numOfPairs>=k)
            {
                freq[nums[i]]--;
                numOfPairs-=freq[nums[i]];
                i++;
            }
            ans+=i;
        }
        return ans;
    }
};
