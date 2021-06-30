class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->left==nullptr && root->right==nullptr)
            return true;
        else if(root->left==nullptr && root->right!=nullptr)
            return isUnivalTree(root->right) && root->right->val==root->val;
        else if(root->left!=nullptr && root->right==nullptr)
            return isUnivalTree(root->left) && root->left->val==root->val;
        else
            return isUnivalTree(root->left) && root->left->val==root->val && isUnivalTree(root->right) && root->right->val==root->val;
    }
};
