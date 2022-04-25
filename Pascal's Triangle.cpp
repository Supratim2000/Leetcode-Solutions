class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        int n=numRows;
        vector<vector<int>> pas;
        for(int i=0;i<n;i++)
        {
            vector<int> temp(i+1,1);
            pas.push_back(temp);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                if(j!=0 && i!=j)
                    pas[i][j]=pas[i-1][j]+pas[i-1][j-1];
        return pas;
    }
};
