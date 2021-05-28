class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* resNode=nullptr;
        ListNode* prevNode=nullptr;
        int sum=0,carry=0;
        
        while(true)
        {
            if(p1==nullptr || p2==nullptr)
                break;
            int dig1=p1->val;
            int dig2=p2->val;
            int res=dig1+dig2+carry;
            sum=res%10;
            carry=res/10;
            ListNode* temp=new ListNode(sum);
            
            if(prevNode==nullptr)
            {
                prevNode=temp;
                resNode=prevNode;
            }
            else
            {
                prevNode->next=temp;
                prevNode=prevNode->next;
            }
            
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==nullptr)
        {
            while(p2!=nullptr)
            {
                int res=carry+p2->val;
                sum=res%10;
                carry=res/10;
                ListNode* temp=new ListNode(sum);
                prevNode->next=temp;
                prevNode=prevNode->next;
                p2=p2->next;
            }
        }
        else
        {
            while(p1!=nullptr)
            {
                int res=carry+p1->val;
                sum=res%10;
                carry=res/10;
                ListNode* temp=new ListNode(sum);
                prevNode->next=temp;
                prevNode=prevNode->next;
                p1=p1->next;
            }
        }
        
        if(carry!=0)
        {
            ListNode* temp=new ListNode(carry);
            prevNode->next=temp;
        }
        return resNode;
    }
};
