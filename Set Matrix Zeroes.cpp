//O(m*n) time complexity
//O(1) space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix.at(0).size();
        bool hzr=false;
        bool hzc=false;
        for(int j=0;j<c;j++)
        {
            if(matrix[0][j]==0)
            {
                hzr=true;
                break;
            }
        }
        for(int i=0;i<r;i++)
        {
            if(matrix[i][0]==0)
            {
                hzc=true;
                break;
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
        if(hzr)
            for(int j=0;j<c;j++)
                matrix[0][j]=0;
        if(hzc)
            for(int i=0;i<r;i++)
                matrix[i][0]=0;
    }
};


//O(m*n) time complexity
//O(m+n) space complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix.at(0).size();
        vector<bool> zone(r,false);
        vector<bool> ztwo(c,false);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    zone[i]=true;
                    ztwo[j]=true;
                }
            }
        }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(zone[i] || ztwo[j])
                    matrix[i][j]=0;
    }
};
