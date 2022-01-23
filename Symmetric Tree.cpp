class Solution {
public:
    bool isMirror(TreeNode* r1, TreeNode* r2)
    {
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1->val!=r2->val)
            return false;
        bool mirror_1=isMirror(r1->left,r2->right);
        if(!mirror_1)
            return false;
        bool mirror_2=isMirror(r1->right,r2->left);
        return mirror_2;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};
