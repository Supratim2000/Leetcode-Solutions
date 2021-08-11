class Solution {
public:
    TreeNode* prev=nullptr;
    bool f_time=true;
    TreeNode* ff=nullptr;
    TreeNode* ss=nullptr;
    TreeNode* maybeUsed=nullptr;
    bool flag=true;
    
    void dfs(TreeNode* root)
    {
        if(root==nullptr)
            return;
        dfs(root->left);
        if(f_time)
            f_time=false;
        else
        {
            TreeNode* curNode=root;
            if(prev->val>=root->val)
            {
                if(flag)
                {
                    flag=false;
                    ff=prev;
                    maybeUsed=curNode;
                }
                else
                    ss=curNode;
            }   
        }
        prev=root;
        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        int temp;
        temp=ff->val;
        if(ss==nullptr)
        {
            ff->val=maybeUsed->val;
            maybeUsed->val=temp;
        }
        else
        {
            ff->val=ss->val;
            ss->val=temp;
        }
    }
};
