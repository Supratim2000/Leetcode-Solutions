//Max Heap(O(nlogn))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue <pair<int,int>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//Min Heap(O(nlogn))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        int n=arr.size();
        for(int i=0;i<n;i++)
            pq.push({abs(x-arr[i]),arr[i]});
        while(!pq.empty() && k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//Two pointer(O(n))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n=arr.size();
        int m=n-k-1;
        int low=0;
        int high=n-1;
        while(m-->=0)
            abs(x-arr[low])<=abs(x-arr[high])?high--:low++;
        for(int i=low;i<=high;i++)
            ans.push_back(arr.at(i));
        return ans;
    }
};
