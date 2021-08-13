class Solution {
public:
    
    int sum=0;
    
    int subTreeSum(TreeNode* root)
    {
       if(root==nullptr)
           return 0;
        int leftPart=subTreeSum(root->left);
        int rightPart=subTreeSum(root->right);
        sum+=abs(leftPart-rightPart);
        return root->val+leftPart+rightPart;
    }
    
    int findTilt(TreeNode* root) {
        subTreeSum(root);
        return sum;
    }
};
