class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int cur=n-1;cur>=2;cur--)
        {
            int i=0;
            int j=cur-1;
            while(i<j)
            {
                if(nums[i]<=nums[cur]-nums[j])
                    i++;
                else
                {
                    count+=j-i;
                    j--;
                }
            }
        }
        return count;
    }
};
