class Solution {
public:
    void inorder(TreeNode* root,int& prev,int& sum)
    {
        if(root==nullptr)
            return;
        prev=prev*10+root->val;
        if(root->left==nullptr && root->right==nullptr)
            sum+=prev;
        inorder(root->left,prev,sum);
        inorder(root->right,prev,sum);
        prev/=10;
    }
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int prev=0;
        inorder(root,prev,sum);
        return sum;
    }
};
