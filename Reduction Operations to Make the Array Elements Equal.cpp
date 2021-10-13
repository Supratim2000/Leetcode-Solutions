//Using sorting
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int tempCount=1;
        for(int i=n-2;i>=0;i--,tempCount++)
            if(nums[i]!=nums[i+1])
                count+=tempCount;
        return count;
    }
};

//Using hashing
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        int cur=0;
        int count=0;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        for(auto it=freq.rbegin();it!=freq.rend();it++)
        {
            if(freq.begin()->first!=it->first)
            {
                cur+=(it->second);
                count+=cur;
            }
        }
        return count;
    }
};
