//Method 1
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

//Method 2
class Solution {
public:
    
    bool isLeaf(TreeNode* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr)
            return nullptr;
        TreeNode* leftPart=removeLeafNodes(root->left,target);
        TreeNode* rightPart=removeLeafNodes(root->right,target);
        root->left=leftPart;
        root->right=rightPart;
        if(isLeaf(root) && root->val==target)
            return nullptr;
        return root;
    }
};
