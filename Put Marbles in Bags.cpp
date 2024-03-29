//Sorting
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> arr;
        int n=weights.size();
        long long ans=0;
        for(int i=0;i<n-1;i++)
            arr.push_back(weights[i+1]+weights[i]);
        sort(arr.begin(),arr.end());
        int m=arr.size();
        for(int i=0;i<k-1;i++)
            ans+=arr[i+m-k+1]-arr[i];
        return ans;
    }
};

//Priority Queue
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        long long ans=0;
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<n-1;i++)
        {
            maxHeap.push(weights.at(i+1)+weights.at(i));
            minHeap.push(weights.at(i+1)+weights.at(i));
        }
        for(int i=0;i<k-1;i++)
        {
            ans+=maxHeap.top()-minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }
        return ans;
    }
};
