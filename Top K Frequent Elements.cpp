//Approach 1(Using sorting(with comparator))
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int>b){return a.second>b.second;}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        vector<pair<int,int>> vec;
        vector<int> ans;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        for(auto x: freq)
            vec.push_back({x.first,x.second});
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<k;i++)
            ans.push_back(vec[i].first);
        return ans;
    }
};

//Approach 2(Using Heap)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> ans;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            minHeap.push({it->second,it->first});
            if(minHeap.size()>k)
                minHeap.pop();
        }
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

//Approach3(Using Bucket sort concept) -> Most optimised(O(n))
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        vector<int> bucket[n+1];
        vector<int> ans;
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        for(auto it=freq.begin();it!=freq.end();it++)
            bucket[it->second].push_back(it->first);
        for(int i=n;i>=1;i--)
        {
            if(!bucket[i].empty())
            {
                while(k>0 && !bucket[i].empty())
                {
                    ans.push_back(bucket[i][bucket[i].size()-1]);
                    bucket[i].pop_back();
                    k--;
                }
                if(!k)
                    break;
            }
        }
        return ans;
    }
};
