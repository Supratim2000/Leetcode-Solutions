class Solution {
public:
    
    ListNode* getTail(ListNode* head)
    {
        ListNode* t=head;
        while(t)
        {
            if(t->next==nullptr)
                break;
            t=t->next;
        }
        return t;
    }
    
    //<prev node, mid node>
    pair<ListNode*,ListNode*> middleNode(ListNode* head,ListNode* tail) {
        pair<ListNode*,ListNode*> ans;
        ListNode* s=head;
        ListNode* f=head;
        while(true)
        {
            if(f==tail || f->next==tail)
            {
                ans.second=s;
                break;
            }
            ans.first=s;
            s=s->next;
            if(f || f->next)
                f=f->next->next;
        }
        return ans;
    }
    
    TreeNode* convert(ListNode* head,ListNode* tail)
    {
        if(head==nullptr)
            return nullptr;
        else if(head==tail)
            return new TreeNode(head->val);
        else if(head->next==tail)
        {
            TreeNode* root=new TreeNode(head->val);
            root->right=new TreeNode(tail->val);
            return root;
        }
        else
        {
            pair<ListNode*,ListNode*> prevAndMid=middleNode(head,tail);
            ListNode* curMid=prevAndMid.second;
            ListNode* curPrev=prevAndMid.first;
            TreeNode* treeRoot=new TreeNode(curMid->val);
            TreeNode* leftSubTree=convert(head,curPrev);
            TreeNode* rightSubTree=convert(curMid->next,tail);
            treeRoot->left=leftSubTree;
            treeRoot->right=rightSubTree;
            return treeRoot;
        }
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail=getTail(head);
        TreeNode* treeRoot=convert(head,tail);
        return treeRoot;
    }
};
