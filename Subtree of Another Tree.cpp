class Solution {
public:    
    bool isSameTree(TreeNode* root,TreeNode* subRoot)
    {
        if(!root && !subRoot)
            return true;
        else if(!root || !subRoot)
            return false;
        else
        {
            bool leftSame=isSameTree(root->left,subRoot->left);
            bool rightSame=isSameTree(root->right,subRoot->right);
            bool rootSame=root->val==subRoot->val;
            return leftSame && rightSame && rootSame;
        }
    }
    
    void inorder(TreeNode* root,TreeNode* subRoot,bool& ans,bool& isDone)
    {
        if(!root)
            return;
        
        inorder(root->left,subRoot,ans,isDone);
        
        if(root->val==subRoot->val && !isDone)
        {
            ans=isSameTree(root,subRoot);
            if(ans)
            {
                isDone=true;
                return;
            }
        }
        
        inorder(root->right,subRoot,ans,isDone);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        bool isDone=false;
        inorder(root,subRoot,ans,isDone);
        return ans;
    }
};
