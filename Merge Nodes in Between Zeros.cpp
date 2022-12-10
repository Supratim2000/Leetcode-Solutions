class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* p=head->next;
        ListNode* h=nullptr;
        ListNode* t=nullptr;
        while(p)
        {
            sum+=p->val;
            if(p->val==0)
            {
                if(h==nullptr)
                {
                    h=new ListNode(sum);
                    t=h;
                }
                else
                {
                    t->next=new ListNode(sum);
                    t=t->next;
                }
                sum=0;
            }
            p=p->next;
        }
        return h;
    }
};
