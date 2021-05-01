//Method 1
//O(mlog(n)) time complexity
/*class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int row=grid.at(0).size();
        for(int i=0;i<grid.size();i++)
        {
            int negIndx=startNeg(grid.at(i));
            if(negIndx!=-1)
            {
                ans+=(row-negIndx);
            }
        }
        return ans;
    }
    
    int startNeg(vector<int>& arr)
    {
        int l=0;
        int h=arr.size()-1;
        int mid;
        int ans=-1;
        while(l<=h)
        {
            mid=l+((h-l)/2);
            if(arr[mid]<0)
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};*/

//Method 2
//O(m+n) time complexity
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j=0;
        int count=0;
        int n=grid.at(0).size();
        int m=grid.size();
        int i=n-1;
        if(grid[m-1][n-1]>=0)
            return 0;
        else if(grid[0][0]<0)
            return m*n;
        while(i>=0 && j<m)
        {
            if(grid[j][i]<0)
            {
                count+=(m-j);
                i--;
            }
            else
            {
                while(grid[j][i]>=0)
                {
                    j++;
                    if(j==m)
                        break;
                }
            }
        }
        return count;
    }
};
