class Solution {
public:
    bool hasPath(ListNode* head, TreeNode* root)
    {
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val==head->val)
            return hasPath(head->next,root->left) || hasPath(head->next,root->right);
        return false;
    }
    
    void dfs(ListNode* head, TreeNode* root,bool& isFound)
    {
        if(!root)
            return;
        if(root->val==head->val)
        {
            if(hasPath(head,root))
            {
                isFound=true;
                return;
            }
        }
        dfs(head,root->left,isFound);
        dfs(head,root->right,isFound);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool isFound=false;
        dfs(head,root,isFound);
        return isFound;
    }
};
