class Solution {
public:
    
    void inorder(TreeNode* root, long &minDif, int &prevNode)
    {
        if(root==nullptr)
            return;
        inorder(root->left,minDif,prevNode);
        if(prevNode!=INT_MIN)
            minDif=min((int)minDif,root->val-prevNode);
        prevNode=root->val;
        inorder(root->right,minDif,prevNode);
    }
    
    int getMinimumDifference(TreeNode* root) {
        long minDif=INT_MAX;
        int prevNode=INT_MIN;
        inorder(root,minDif,prevNode);
        return (int)minDif;
    }
};
