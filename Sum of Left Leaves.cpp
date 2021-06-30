class Solution {
public:
    
    void helper(TreeNode* root,int& sum)
    {
        if(root==nullptr)
            return;
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
            sum+=root->left->val;
        helper(root->left,sum);
        helper(root->right,sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
    }
};
