class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int row=mat.size();
        int col=mat.at(0).size();
        int leftRow=0;
        int leftCol=0;
        int upRow=0;
        int upCol=0;
        int count=0;
        int itTime=row-1+col;
        while(count!=itTime)
        {   
            int topRow=upRow;
            int topCol=upCol;
            int downRow=leftRow;
            int downCol=leftCol;   
            if(count%2!=0)
            {
                while(topRow!=downRow+1)
                    ans.push_back(mat.at(topRow++).at(topCol--));
            }
            else
            {
                while(downRow!=topRow-1)
                    ans.push_back(mat.at(downRow--).at(downCol++));
            }
            upCol<col-1?upCol++:upRow++;
            leftRow<row-1?leftRow++:leftCol++;
            count++;
        }
        return ans;
    }
};
