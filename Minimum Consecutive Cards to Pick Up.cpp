class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int ans=INT_MAX;
        unordered_map<int,int> lastIndex;
        for(int i=0;i<n;i++)
        {
            if(lastIndex.find(cards.at(i))!=lastIndex.end())
                ans=min(i-lastIndex[cards.at(i)]+1,ans);
            lastIndex[cards.at(i)]=i;
        }
        return ans!=INT_MAX?ans:-1;
    }
};
