class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int count=k;
        bool done=false;
        int arr[101]={0};
        vector<int> v;
        int r=mat.size();
        int c=mat.at(0).size();
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                if(mat[j][i]==0 && arr[j]!=1)
                {
                    done=true;
                    arr[j]=1;
                    v.push_back(j);
                    count--;
                    if(count==0)
                        return v;
                }
            }
        }
        if(!done)
        {
            v.push_back(0);
            return v;
        }
        else if(count!=0)
        {
            for(int i=0;i<r;i++)
            {
                if(mat[i][c-1]==1 && count!=0)
                {
                    v.push_back(i);
                    count--;
                }
            }
        }
        return v;
    }
};
