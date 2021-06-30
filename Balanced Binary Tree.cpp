class Solution {
public:
    
    int height(TreeNode* root)
    {
        return !root?0:max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool left=isBalanced(root->left);
        if(!left) return false;
        bool right=isBalanced(root->right);
        if(!right) return false;
        return left && right && abs(height(root->left)-height(root->right))<=1;
    }
};
