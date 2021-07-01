class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return false;
        if(root->val==targetSum && root->left==nullptr && root->right==nullptr)
            return true;
        
        bool hasLeft=hasPathSum(root->left,targetSum-root->val);
        if(hasLeft)
            return true;
        else
        {
            bool hasRight=hasPathSum(root->right,targetSum-root->val);
            if(hasRight)
                return true;
        }    
        return false;
    }
};
