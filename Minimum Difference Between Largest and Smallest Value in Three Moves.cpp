//Sorting
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)
            return 0;
        sort(nums.begin(),nums.end());
        int minDif=INT_MAX;
        for(int i=0;i<4;i++)
            minDif=min(nums[n-4+i]-nums[i],minDif);
        return minDif;
    }
};

//Priority Queue
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)
            return 0;
        int minDif=INT_MAX;
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<int> elements;
        for(auto x: nums)
        {
            maxHeap.push(x);
            minHeap.push(x);
            if(maxHeap.size()>4)
                maxHeap.pop();
            if(minHeap.size()>4)
                minHeap.pop();
        }
        while(!maxHeap.empty())
        {
            elements.push_back(maxHeap.top());
            maxHeap.pop();
        }
        while(!minHeap.empty())
        {
            elements.push_back(minHeap.top());
            minHeap.pop();
        }
        for(int i=0,j=3,k=4;i<4;i++,j--,k++)
            minDif=min(elements[k]-elements[j],minDif);
        return minDif;
    }
};
