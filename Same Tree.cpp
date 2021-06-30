class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr && q!=nullptr)
            return false;
        if(p!=nullptr && q==nullptr)
            return false;
        return isSameTree(p->left,q->left)==true && isSameTree(p->right,q->right)==true && p->val==q->val;
    }
};
