class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> l1=edges[0];
        vector<int> l2=edges[1];
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(l1[i]==l2[j])
                    return l1[i];
        return INT_MAX;
    }
};
