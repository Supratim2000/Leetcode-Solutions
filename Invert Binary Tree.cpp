class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* invertedLeft=invertTree(root->left);
        TreeNode* invertedRight=invertTree(root->right);
        root->left=invertedRight;
        root->right=invertedLeft;
        return root;
    }
};
