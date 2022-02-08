class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode* ins=new TreeNode(val);
        TreeNode* cur=root;
        TreeNode* prv=nullptr;
        while(cur)
        {
            prv=cur;
            cur=cur->val>val?cur->left:cur->right;
        }
        val<prv->val?prv->left=ins:prv->right=ins;
        return root;
    }
};
