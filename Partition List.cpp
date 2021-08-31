//Method 1
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


//Method 2(Using two pointer)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int count=1;
        ListNode* newHead;
        ListNode* d1=new ListNode(INT_MAX);
        ListNode* d2=new ListNode(INT_MAX);
        ListNode* l1=d1;
        ListNode* l2=d2;
        ListNode* p=head;
        while(p)
        {
            if(count&1)
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
            count++;
            p=p->next;
        }
        newHead=d1->next;
        l1->next=d2->next;
        delete d1;
        delete d2;
        return newHead;
    }
};
