class Solution {
public:
    void rev_inorder(TreeNode* root,int& prev_val,bool& f_time)
    {
        if(root==nullptr)
            return ;
        rev_inorder(root->right,prev_val,f_time);
        if(f_time==true)
        {
            f_time=false;
            prev_val=root->val;
        }
        else
        {
            root->val=prev_val+root->val;
            prev_val=root->val;
        }
        rev_inorder(root->left,prev_val,f_time);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        int prev_val=-1;
        bool f_time=true;
        rev_inorder(root,prev_val,f_time);
        return root;
    }
};
