class Solution {
public:  
    //<Head, Tail>
    pair<TreeNode*,TreeNode*> flat(TreeNode* root)
    {
        if(!root)
            return {nullptr,nullptr};
        else if(!root->left && !root->right)
            return {root,root};
        else if(!root->left)
        {
            pair<TreeNode*,TreeNode*> right=flat(root->right);
            root->right=right.first;
            return {root,right.second};
        }
        else if(!root->right)
        {
            pair<TreeNode*,TreeNode*> left=flat(root->left);
            root->right=left.first;
            root->left=nullptr;
            return {root,left.second};
        }
        else
        {
            pair<TreeNode*,TreeNode*> left=flat(root->left);
            pair<TreeNode*,TreeNode*> right=flat(root->right);
            root->left=nullptr;
            root->right=left.first;
            left.second->right=right.first;
            return {root,right.second};
        }
    }
    
    void flatten(TreeNode* root) {
        flat(root);
    }
};
