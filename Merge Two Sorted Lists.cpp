class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* head = new ListNode(-1);
        ListNode* temp;
        if(l1==nullptr && l2==nullptr)
            return nullptr;
        else if(l1==nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
        else
        {
            if(a->val < b->val)
            {
                temp = a;
                a = a->next;
            }
            else
            {
                temp = b;
                b = b->next;
            }
            head->next = temp;
            
            while(a!=nullptr && b!=nullptr)
            {
                if(a->val < b->val)
                {
                    temp->next = a;
                    a = a->next;
                    temp = temp->next;
                }
                else if(a->val > b->val)
                {
                    temp->next = b;
                    b = b->next;
                    temp = temp->next;
                }
                else
                {
                    if(temp->next == b)
                    {
                        temp = temp->next;
                        b = b->next;
                        temp->next = a;
                        temp = temp->next;
                        a = a->next;
                    }
                    else
                    {
                        temp = temp->next;
                        a = a->next;
                        temp->next = b;
                        temp = temp->next;
                        b = b->next;
                    }
                }
            }
        
            if(a==nullptr)
                temp->next=b;
            else
                temp->next=a;
            
            return head->next;
        }
    }
};
