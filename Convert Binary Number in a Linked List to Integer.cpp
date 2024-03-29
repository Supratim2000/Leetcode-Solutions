class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head)
        {
            ans=ans<<1;
            ans=ans | head->val;
            head=head->next;
        }
        return ans;
    }
};
