class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue <int, vector<int>, greater<int>> pq; 
        unordered_map<int,int> freq;
        for(auto x: arr) {
            freq[x]++;
        }

        for(auto x: freq) {
            pq.push(x.second);
        }

        while(k) {
            int topElFreq=pq.top();
            if(k>=topElFreq) {
                k-=topElFreq;
                pq.pop();
            } else {
                break;
            }
        }
        return pq.size();
    }
};
