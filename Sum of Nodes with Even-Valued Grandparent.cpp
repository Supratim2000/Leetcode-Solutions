class Solution {
public:
    void dfs(TreeNode* root,int& s)
    {
        if(!root)
            return;
        dfs(root->left,s);
        
        if(root->val%2==0)
        {
            if(root->left!=nullptr)
            {
                TreeNode* t=root->left;
                if(t->left!=nullptr)
                    s+=t->left->val;
                if(t->right!=nullptr)
                    s+=t->right->val;
            }
            if(root->right!=nullptr)
            {
                TreeNode* t=root->right;
                if(t->left!=nullptr)
                    s+=t->left->val;
                if(t->right!=nullptr)
                    s+=t->right->val;
            }
        }
        dfs(root->right,s);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int sum=0;
        dfs(root,sum);
        return sum;
    }
};
