class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        pair<int,int> p=make_pair(intervals[0][0],intervals[0][1]);
        
        for(int i=0;i<intervals.size();i++)
        {
            if(p.second>=intervals[i][0])
                p.second=max(p.second,intervals[i][1]);
            else
            {
                temp.push_back(p.first);
                temp.push_back(p.second);
                p.first=intervals[i][0];
                p.second=intervals[i][1];
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        temp.push_back(p.first);
        temp.push_back(p.second);
        ans.push_back(temp);
        return ans;
    }
};
