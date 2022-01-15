class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr)
            return nullptr;
        ListNode* prv=nullptr;
        ListNode* s=head;
        ListNode* f=head;
        while(f)
        {
            prv=s;
            s=s->next;
            if(f)
                f=f->next->next;
            if(f && f->next==nullptr)
                break;
        }
        prv->next=s->next;
        s->next=nullptr;
        delete s;
        return head;
    }
};
