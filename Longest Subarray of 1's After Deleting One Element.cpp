class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int freqZero=0;
        int ans=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            if(nums.at(j)==0)
                freqZero++;
            if(freqZero>1)
            {
                while(nums.at(i)==1)
                    i++;
                freqZero--;
                i++;
            }
            ans=max(j-i,ans);
            j++;
        }
        return ans;
    }
};
