class Solution {
public:
    
    void dfs(TreeNode* root,int num,int& sum)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr && root->right==nullptr)
        {
            int endNum=(num<<1) | root->val;
            sum+=endNum;
        }
        if(root->left)
            dfs(root->left,num<<1 | root->val,sum);
        if(root->right)
            dfs(root->right,num<<1 | root->val,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        dfs(root,0,sum);
        return sum;
    }
};
