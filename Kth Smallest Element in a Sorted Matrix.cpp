//Using priority queue
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
        return maxHeap.top();;
    }
};
