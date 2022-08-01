class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        int x=cheeseSlices-((4*cheeseSlices-tomatoSlices)/2);
        int y=(4*cheeseSlices-tomatoSlices)/2;
        if((4*cheeseSlices-tomatoSlices)%2==0 && x>=0 && y>=0)
        {
            ans.push_back(x);
            ans.push_back(y);
        }
        return ans;
    }
};
