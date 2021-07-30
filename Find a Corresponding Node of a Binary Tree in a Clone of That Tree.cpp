//If values are uniqueue in tree
class Solution {
public:
    
    TreeNode* ans=nullptr;
    
    void dfs(TreeNode* cloned, int target_val)
    {
        if(cloned==nullptr)
            return ;
        dfs(cloned->left,target_val);
        if(cloned->val==target_val)
        {
            ans=cloned;
            return;
        }
        dfs(cloned->right,target_val);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int target_val=target->val;
        dfs(cloned,target_val);
        return ans;
    }
};


//If values are repeated in tree
class Solution {
public:
    TreeNode* ans=nullptr;
    void dfs(TreeNode* original,TreeNode* cloned,TreeNode* target)
    {
        if(cloned==nullptr)
            return ;
        dfs(original->left,cloned->left,target);
        if(target==original)
        {
            ans=cloned;
            return;
        }
        dfs(original->right,cloned->right,target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned,target);
        return ans;
    }
};
