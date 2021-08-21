class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        else
        {
            bool sameRootVal=(root1->val==root2->val);
            bool oppFlip=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
            bool sameFlip=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
            return sameRootVal && oppFlip || sameFlip;
        }
    }
};
