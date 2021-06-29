class Solution {
public:
    //Recursive
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr)
            return nullptr;
        if(root->val==val)
            return root;
        else if(root->val<val)
            return searchBST(root->right,val);
        return searchBST(root->left,val);
    }
    
    //Iterative
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr)
            return nullptr;
        TreeNode* p=root;
        while(p)
        {
            if(p->val==val)
                return p;
            else if(p->val<val)
                p=p->right;
            else
                p=p->left;
        }
        return nullptr;
    }
};
