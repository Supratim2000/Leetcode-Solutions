class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        vector<int> bitNum(32,0);
        for(auto num: nums)
        {
            for(int i=0;i<32;i++)
            {
                if(((1<<i)&num)!=0)
                {
                    bitNum[i]++;
                }
            }
        }

        for(int i=31;i>=0;i--)
        {
            if(bitNum[i]%3!=0)
                ans=(ans | (1<<i));
        }

        return ans;
    }
};
