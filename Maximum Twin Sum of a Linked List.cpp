class Solution {
public:
    
    ListNode* getMidNode(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f)
        {
            f=f->next->next;
            if(f)
                s=s->next;
        }
        return s;
    }
    int pairSum(ListNode* head) {
        ListNode* mid=getMidNode(head);
        ListNode* prv=mid;
        ListNode* nxt=mid->next;
        ListNode* adv=nxt->next;
        while(nxt)
        {
            nxt->next=prv;
            if(mid==prv)
                prv->next=nullptr;
            prv=nxt;
            nxt=adv;
            if(adv)
                adv=adv->next;
        }
        
        int maxSum=INT_MIN;
        ListNode* h=head;
        ListNode* t=prv;
        
        while(h)
        {
            if(maxSum<h->val+t->val)
                maxSum=h->val+t->val;
                h=h->next;
                t=t->next;
        }
        return maxSum;
    }
};
