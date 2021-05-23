/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        do
        {
            slow=slow->next;
            if(fast==nullptr || fast->next==nullptr)
                return nullptr;
            fast=fast->next->next;
        }while(slow!=fast);
        
        int pos=0;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
            pos++;
        }
        return slow;
    }
};
