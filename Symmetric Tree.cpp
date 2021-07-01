class Solution {
public:
    
    bool checkMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1==nullptr && root2==nullptr)
            return true;
        if(root1==nullptr || root2==nullptr)
            return false;
        bool isLeftMirror=checkMirror(root1->left,root2->right);
        if(!isLeftMirror)
            return false;
        bool isRightMirror=checkMirror(root1->right,root2->left);
        if(!isRightMirror)
            return false;
        return isLeftMirror && isRightMirror && root1->val==root2->val;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->left==nullptr && root->right==nullptr)
            return true;
        if(root->left==nullptr || root->right==nullptr)
            return false;
        return checkMirror(root->left,root->right);
    }
};
