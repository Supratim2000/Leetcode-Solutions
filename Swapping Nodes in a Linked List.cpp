class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ff=head;
        ListNode* ss=head;
        ListNode* x=nullptr;
        for(int i=0;i<k-1;i++)
            ff=ff->next;
        x=ff->next;
        while(x)
        {
            x=x->next;
            ss=ss->next;
        }
        if(ff!=ss)
            swapNum(ff->val,ss->val); 
        return head;
    }
    void swapNum(int &x, int &y)
    {
        if(x==y)
            return;
        int t=x;
        x=y;
        y=t;
    }
};
