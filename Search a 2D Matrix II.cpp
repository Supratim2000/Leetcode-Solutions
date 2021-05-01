typedef long long ll;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix.at(0).size();
        int start_r=r-1;
        int start_c=0;
        while(start_r!=-1 && start_c!=c)
        {
            if(matrix[start_r][start_c]==target)
                return true;
            else if(matrix[start_r][start_c]>target)
                start_r--;
            else
                start_c++;
        }
        return false;
    }
};
