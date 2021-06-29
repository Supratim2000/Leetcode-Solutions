class Solution {
public:    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)
            return 0;
        int subtreeSum=rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        return root->val>=low && root->val<=high?subtreeSum+root->val:subtreeSum;
    }
};
