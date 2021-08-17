class Solution {
public:
    //pair<Sum,Carry>
    pair<int,int> getSumCarry(int n)
    {
        pair<int,int> ans;
        ans.first=n%10;
        ans.second=n/10;
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a;
        stack<int> b;
        for(ListNode* x=l1;x;x=x->next)
            a.push(x->val);
        for(ListNode* x=l2;x;x=x->next)
            b.push(x->val);
        ListNode* head=nullptr;
        pair<int,int> sumCar({0,0});
        while(!a.empty() && !b.empty())
        {   
            int curRes=a.top()+b.top()+sumCar.second;
            pair<int,int> temp=getSumCarry(curRes);
            int curSum=temp.first;
            int curCarry=temp.second;
            ListNode* t=new ListNode(curSum);
            if(head!=nullptr)
                t->next=head;
            head=t;
            sumCar.first=curSum;
            sumCar.second=curCarry;    
            a.pop();
            b.pop();
        }
        
        if(a.empty())
        {
            while(!b.empty())
            {
                int curRes=b.top()+sumCar.second;
                b.pop();
                pair<int,int> temp=getSumCarry(curRes);
                int curSum=temp.first;
                int curCarry=temp.second;
                ListNode* t=new ListNode(curSum);
                t->next=head;
                head=t;
                sumCar.first=curSum;
                sumCar.second=curCarry;
            }
        }
        else if(b.empty())
        {
            while(!a.empty())
            {
                int curRes=a.top()+sumCar.second;
                a.pop();
                pair<int,int> temp=getSumCarry(curRes);
                int curSum=temp.first;
                int curCarry=temp.second;
                ListNode* t=new ListNode(curSum);
                t->next=head;
                head=t;
                sumCar.first=curSum;
                sumCar.second=curCarry;
            }
        }
        
        if(sumCar.second)
        {
            ListNode* t=new ListNode(1);
            t->next=head;
            head=t;
        }
        return head;
    }
};
