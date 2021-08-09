class Solution {
public:
    void reverseInorder(TreeNode* root,int& prev)
    {
        if(root==nullptr)
            return;
        reverseInorder(root->right,prev);
        root->val+=prev;
        prev=root->val;
        reverseInorder(root->left,prev);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int prev=0;
        reverseInorder(root,prev);
        return root;
    }
};
