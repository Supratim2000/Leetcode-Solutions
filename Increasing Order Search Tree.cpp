class Solution {
public:
    TreeNode* prevNode=nullptr;
    TreeNode* mainNode=nullptr;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        TreeNode* node=new TreeNode(root->val);
        if(mainNode==nullptr)
            mainNode=node;
        if(prevNode!=nullptr)
            prevNode->right=node;
        prevNode=node;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return mainNode;
    }
};
