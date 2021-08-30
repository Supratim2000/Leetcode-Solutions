class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* permHead=list1;
        ListNode* f=list1;
        ListNode* s=list1;
        ListNode* temp=nullptr;
        ListNode* prev=nullptr;
        for(int i=0;i<a-1;i++)
            f=f->next;
        temp=f->next;
        s=f;
        for(int i=0;i<b-a+2;i++)
            s=s->next;
        f->next=list2;
        while(list2->next)
            list2=list2->next;
        list2->next=s;
        while(temp!=s)
        {
            prev=temp;
            temp=temp->next;
            delete prev;
        }
        return permHead;
    }
};
