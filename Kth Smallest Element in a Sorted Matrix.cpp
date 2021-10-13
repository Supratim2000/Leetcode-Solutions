//Using Heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> maxHeap;
        for(auto row: matrix)
            for(auto element: row)
                maxHeap.push(element);
        for(int i=0;i<n*n-k;i++)
            maxHeap.pop();
        return maxHeap.top();
    }
};

//Using Binary search
class Solution {
public:
    int smallerThan(vector<vector<int>>& matrix,int n,int val)
    {
        int count=0;
        int i=0;
        int j=n-1;
        while(i<n && j>=0)
        {
            if(matrix[i][j]<=val)
            {
                count+=j+1;
                i++;
            }
            else
                j--;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        if(k==1)
            return matrix[0][0];
        if(k==n*n)
            return matrix[n-1][n-1];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int m=smallerThan(matrix,n,mid);
            if(m<k)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
