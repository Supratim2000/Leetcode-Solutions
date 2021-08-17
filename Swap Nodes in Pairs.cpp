class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* t=nullptr;
        ListNode* h=nullptr;
        ListNode* f=head;
        ListNode* s=head->next;
        while(true)
        {
            if(!h)
                h=s;
            t=s->next;
            s->next=f;
            if(!t)
            {
                f->next=nullptr;
                break;
            }
            f->next=t->next;
            if(!f->next)
            {
                f->next=t;
                break;
            }  
            f=t;
            s=t->next;
        }
        return h;
    }
};
