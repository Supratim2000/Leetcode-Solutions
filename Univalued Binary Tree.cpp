class Solution {
public:
    //Method 1
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
    
    //Method 2
    int prevVal=INT_MAX;
    bool isUTree=true;
    
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        if(prevVal==INT_MAX)
            prevVal=root->val;
        else
        {
            if(prevVal!=root->val)
            {
                isUTree=false;
                return;
            }
        }
        inorder(root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
        inorder(root);
        return isUTree;
    }
};
