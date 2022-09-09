class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--)
        {
            int cur=temperatures.at(i);
            while(!st.empty() && st.top().first<=cur)
                st.pop();
            if(st.empty())
                ans.at(i)=0;
            else
                ans.at(i)=st.top().second-i;
            st.push({cur,i});
        }
        return ans;
    }
};
