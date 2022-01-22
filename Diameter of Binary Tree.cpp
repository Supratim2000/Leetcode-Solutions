class Solution {
public:
    int height(TreeNode* root,int& dia)
    {
        if(!root)
            return 0;
        int left=height(root->left,dia);
        int right=height(root->right,dia);
        if(left+right>dia)
            dia=left+right;
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=INT_MIN;
        height(root,dia);
        return dia;
        
    }
};
