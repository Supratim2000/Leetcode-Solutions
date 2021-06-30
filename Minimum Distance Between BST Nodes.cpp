class Solution {
public:
    int prevNodeVal=-10000000;
    int minDif=10000000;
    
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        if(root->val-prevNodeVal<minDif)
            minDif=root->val-prevNodeVal;
        prevNodeVal=root->val;
        inorder(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDif;
    }
};
