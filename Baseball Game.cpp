class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        int score=0;
        vector<int> st;
        for(int i=0;i<n;i++)
        {
            if(ops[i][0]=='+')
                st.push_back(st.at(st.size()-1)+st.at(st.size()-2));
            else if(ops[i][0]=='D')
                st.push_back(2*st.at(st.size()-1));
            else if(ops[i][0]=='C')
                st.pop_back();
            else
                st.push_back(stoi(ops.at(i)));
        }
        for(auto x: st)
            score+=x;
        return score;
    }
};
