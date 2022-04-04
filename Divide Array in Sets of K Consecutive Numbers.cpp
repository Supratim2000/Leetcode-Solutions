class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)
            return false;
        map<int,int> freq;
        for(auto x: nums)
            freq[x]++;
        int op=n/k;
        while(op--)
        {
            int smallInMap=freq.begin()->first;
            for(int i=0;i<k;i++)
            {
                if(freq.find(smallInMap+i)==freq.end())
                    return false;
                else
                {
                    freq[smallInMap+i]--;
                    if(freq[smallInMap+i]==0)
                        freq.erase(smallInMap+i);
                }
            }
        }
        return true;
    }
};
