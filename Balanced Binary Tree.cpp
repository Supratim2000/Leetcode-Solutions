//Unoptimised O(n^2)
class Solution {
public:
    
    int height(TreeNode* root)
    {
        return !root?0:max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool left=isBalanced(root->left);
        if(!left) return false;
        bool right=isBalanced(root->right);
        if(!right) return false;
        return left && right && abs(height(root->left)-height(root->right))<=1;
    }
};

//Optimised O(n)
class Solution {
public:    
    int height(TreeNode* root,bool &balanced)
    {
        if(root==nullptr)
            return 0;
        int leftHeight=height(root->left,balanced);
        int rightHeight=height(root->right,balanced);
        if(abs(leftHeight-rightHeight)>1)
        {
            balanced=false;
            return 10000;
        }
        return max(leftHeight,rightHeight)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        height(root,balanced);
        return balanced;
    }
    
};
