class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        unordered_map<int,int> freq;
        while(j<n)
        {
            freq[nums[j]]++;
            sum+=nums[j];
            while(freq[nums[j]]>1)
            {
                freq[nums[i]]--;
                sum-=nums[i];
                if(freq[nums[i]]==0)
                    freq.erase(nums[i]);
                i++;
            }
            ans=max(sum,ans);
            j++;
        }
        return ans;
    }
};
