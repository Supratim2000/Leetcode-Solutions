//Solution - 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root==nullptr?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//Solution - 2
class Solution {
public:    
    void helper(TreeNode* root,int curDep,int& maxDep) {
        if(!root)
            return;
        helper(root->left,curDep+1,maxDep);
        if(curDep>maxDep)
            maxDep=curDep;
        helper(root->right,curDep+1,maxDep);
    }
    
    int maxDepth(TreeNode* root) {
        int maxDep=0;
        helper(root, 1, maxDep);
        return maxDep;
    }
};
