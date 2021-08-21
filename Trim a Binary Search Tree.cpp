class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return nullptr;
        TreeNode* trimedLeft=trimBST(root->left,low,high);
        TreeNode* trimedRight=trimBST(root->right,low,high);
        if(root->val>=low && root->val<=high)
        {
            root->left=trimedLeft;
            root->right=trimedRight;
        }
        else if(root->val>high)
            return trimedLeft;
        else
            return trimedRight;
        return root;
    }
};
