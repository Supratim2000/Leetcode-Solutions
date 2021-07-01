class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)
            return nullptr;
        else if(root1!=nullptr && root2==nullptr)
            return root1;
        else if(root1==nullptr && root2!=nullptr)
            return root2;
        else
        {
            TreeNode* mergedLeft=mergeTrees(root1->left,root2->left);
            TreeNode* mergedRight=mergeTrees(root1->right,root2->right);
            TreeNode* mergedRoot=new TreeNode(root1->val+root2->val);
            mergedRoot->left=mergedLeft;
            mergedRoot->right=mergedRight;
            return mergedRoot;
        }
    }
};
