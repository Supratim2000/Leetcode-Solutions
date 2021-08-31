class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead;
        ListNode* d1=new ListNode(INT_MAX);
        ListNode* d2=new ListNode(INT_MAX);
        ListNode* l1=d1;
        ListNode* l2=d2;
        ListNode* p=head;
        while(p)
        {
            if(p->val<x)
            {
                l1->next=p;
                l1=p;
                l2->next=nullptr;
            }
            else
            {
                l2->next=p;
                l2=p;
                l1->next=nullptr;
            }
            p=p->next;
        }
        if(!d1->next)
            newHead=d2->next;
        else if(!d2->next)
            newHead=d1->next;
        else
        {
            newHead=d1->next;
            l1->next=d2->next;
        }
        delete d1;
        delete d2;
        return newHead;
    }
};
