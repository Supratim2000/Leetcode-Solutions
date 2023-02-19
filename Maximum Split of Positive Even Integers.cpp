class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum&1)
            return {};
        vector<long long> ans;
        long long temp=finalSum;
        int cur=2;
        while(true)
        {
            if(!ans.empty() && temp<=ans.at(ans.size()-1))
            {
                ans.at(ans.size()-1)=ans.at(ans.size()-1)+temp;
                break;
            }
            else
            {
                ans.push_back(cur);
                temp-=cur;
                cur+=2;
            }
        }
        return ans;
    }
};
