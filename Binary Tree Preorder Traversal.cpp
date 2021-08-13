class Solution {
public:
    
    void dfs(TreeNode* root,vector<int>& arr)
    {
        if(root==nullptr)
            return;
        arr.push_back(root->val);
        dfs(root->left,arr);
        dfs(root->right,arr);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};
