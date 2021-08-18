class Solution {
public:
    
    bool isLeaf(TreeNode* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    void postOrder(TreeNode* root, TreeNode* parent, int target,bool& isDeleteRoot)
    {
        if(!root)
            return;
        postOrder(root->left,root,target,isDeleteRoot);
        postOrder(root->right,root,target,isDeleteRoot);
        
        if(isLeaf(root) && root->val==target)
        {
            if(!parent)
            {
                isDeleteRoot=true;
                return;
            }
            if(parent->left==root)
            {
                delete parent->left;
                parent->left=nullptr;
            }
            else if(parent->right==root)
            {
                delete parent->right;
                parent->right=nullptr;
            }
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool isDeleteRoot=false;
        TreeNode* curParent=nullptr;
        postOrder(root,curParent,target,isDeleteRoot);
        if(isDeleteRoot)
            return nullptr;
        return root;
    }
};
