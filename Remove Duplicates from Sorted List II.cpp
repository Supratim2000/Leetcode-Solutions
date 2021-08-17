class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* p=nullptr;
        ListNode* q=head;
        ListNode* r=head->next;
        while(r)
        {
            if(q->val==r->val)
            {
                while(r && r->val==q->val)
                    r=r->next;
                
                if(p==nullptr)
                {
                    head=r;
                    q=r;
                    if(r==nullptr)
                        return nullptr;
                    r=r->next;
                }
                else
                {
                    if(r==nullptr)
                    {
                        p->next=nullptr;
                        break;
                    }
                    p->next=r;
                    q=r;
                    r=r->next;
                }
            }
            else
            {
                p=q;
                q=r;
                r=r->next;
            }
        }
        return head;
    }
};
