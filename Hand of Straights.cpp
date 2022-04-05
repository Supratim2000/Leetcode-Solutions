class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        bool isPossible=true;
        int n=hand.size();
        if(n%groupSize!=0)
            return false;
        int steps=n/groupSize;
        map<int,int> freq;
        for(auto x: hand)
            freq[x]++;
        while(steps--)
        {
            auto initVal=freq.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(freq.find(i+initVal)!=freq.end())
                {
                    freq[i+initVal]--;
                    if(freq[i+initVal]==0)
                        freq.erase(i+initVal);
                }
                else
                {
                    isPossible=false;
                    break;
                }
            }
        }
        return isPossible;
    }
};
