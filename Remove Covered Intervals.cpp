class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){return a[0]==b[0]?b[1]>b[0]:a[0]<b[0];}
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=n;
        sort(intervals.begin(),intervals.end(),comp);
        int a=intervals[0][0];
        int b=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][1]<=b)
                count--;
            else
            {
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        return count;
    }
};
