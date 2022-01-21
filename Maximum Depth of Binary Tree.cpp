//Solution - 1(Beginner friendly)
class Solution {
public:    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int leftMaxDepth=maxDepth(root->left);
        int rightMaxDepth=maxDepth(root->right);
        return max(leftMaxDepth,rightMaxDepth)+1;
    }
};

//Solution - 2(1 line solution)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root==nullptr?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//Solution - 3(DFS)
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
