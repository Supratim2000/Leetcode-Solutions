class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> q;
        //if case when window size greater than or equal to size of vector
        if(k>=n) {
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        } else {
            int i=0;
            int j=0;
            while(j<n) {
                int curElement=nums.at(j);
                while(!q.empty() && q.back()<curElement) {
                    q.pop_back();
                }
                q.push_back(curElement);
                if(j-i+1<k) {
                    j++;
                } else {
                    int maxInWindow=q.front();
                    ans.push_back(maxInWindow);
                    if(q.front()==nums.at(i)) {
                        q.pop_front();
                    }
                    i++;
                    j++;
                }
            }
            return ans;
        }
    }
};
