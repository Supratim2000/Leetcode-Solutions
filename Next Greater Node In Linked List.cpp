class Solution {
public:
    pair<ListNode*,int> reverseList(ListNode* head) {
        if(head==nullptr)
        {
            pair<ListNode*,int>ans;
            ans.first=nullptr;
            ans.second=0;
            return ans;
        }
        if(head->next==nullptr)
        {
            pair<ListNode*,int>ans;
            ans.first=head;
            ans.second=1;
            return ans;
        }
        int count=0;
        ListNode* p=nullptr;
        ListNode* q=head;
        ListNode* r=head->next;
        
        while(q)
        {
            q->next=p;
            p=q;
            count++;
            q=r;
            if(r)
                r=r->next;
        }
        pair<ListNode*,int>ans;
        ans.first=p;
        ans.second=count;
        return ans;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        pair<ListNode*,int> res=reverseList(head);
        int n=res.second;
        head=res.first;
        vector<int> ans(n,0);
        int i=n-1;
        stack<int> st;
        while(head)
        {
            if(!st.empty())
            {
                if(st.top()>head->val)
                {
                    ans[i]=st.top();
                    st.push(head->val);
                }
                else
                {
                    while(!st.empty() && st.top()<=head->val)
                        st.pop();
                    if(st.empty())
                        st.push(head->val);
                    else
                    {
                        ans[i]=st.top();
                        st.push(head->val);
                    }
                }
            }
            else
                st.push(head->val);
            i--;
            head=head->next;
        }
        return ans;
    }
};
