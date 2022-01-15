class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int minDist=INT_MAX;
        int firstCrit=-1;
        int lastCrit=-1;
        int prevCrit=-1;
        int curCrit=-1;
        ListNode* p=head->next;
        ListNode* q=head;
        int countCrit=0;
        int size=2;
        while(p->next!=nullptr)
        {
            
            if(((q->val<p->val) && (p->next->val<p->val)) || ((q->val>p->val) && (p->next->val>p->val)))
            {
                if(firstCrit==-1)
                {
                    firstCrit=size;
                    prevCrit=size;
                }
                lastCrit=size;
                countCrit++;
                if(countCrit>1)
                {
                    curCrit=size;
                    minDist=min(minDist,curCrit-prevCrit);
                    prevCrit=curCrit;
                }
            }
            size++;
            q=p;
            p=p->next;
        }
        
        if(countCrit<2)
        {
            for(int i=0;i<2;i++)
                ans.push_back(-1);
        }
        else
        {
            ans.push_back(minDist);
            ans.push_back(lastCrit-firstCrit);
        }
        return ans;
    }
};
