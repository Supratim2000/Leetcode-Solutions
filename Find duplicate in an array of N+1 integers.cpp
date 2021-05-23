class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==2)
            return nums.at(0);
        int slow=nums[0];
        int fast=nums[0];
        int temp=slow;
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=temp;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
