class Solution {
public:
    void inorder(TreeNode* root, int& count, int& ans)
    {
        if(!root)
            return;
        if(ans==-1)
            inorder(root->left, count, ans);
        if(!--count)
        {
            ans=root->val;
            return;
        }
        if(ans==-1)
            inorder(root->right, count, ans);  
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int count=k;
        inorder(root,k,ans);
        return ans;
    }
};
