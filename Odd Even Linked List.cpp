class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        ListNode* p=head;
        ListNode* q=head->next;
        ListNode* t=q;
        ListNode* x=head;
        ListNode* y=head->next;
        while(true)
        {
            x=x->next->next;
            p->next=x;
            p=x;
            
            y=y->next->next;
            q->next=y;
            q=y;
            
            if(!q && !p->next)
            {
                p->next=t;
                break;
            }
            if(!q->next && !p->next->next) {
                p->next=t;
                break;
            }
        }
        return head;
    }
};
