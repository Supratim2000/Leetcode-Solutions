//Method 1 (Without keeping track of parent and grandparent)
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


//Method 2 (Keeping track of parent and grandparent)
class Solution {
public:
    void dfs(TreeNode* root,TreeNode* parent,TreeNode* grandParent,int& s)
    {
        if(!root)
            return;
        if(grandParent && !(grandParent->val&1))
            s+=root->val;
        dfs(root->left,root,parent,s);
        dfs(root->right,root,parent,s);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        dfs(root,nullptr,nullptr,sum);
        return sum;
    }
};
