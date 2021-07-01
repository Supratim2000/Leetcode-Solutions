class Solution {
public:
    void inorder(TreeNode* root,int &minData,int &minDif,int &minDifVal)
    {
        if(root==nullptr)
            return;
        inorder(root->left,minData,minDif,minDifVal);
        if(root->val-minData<minDif && root->val!=minData)
        {
            minDif=root->val-minData;
            minDifVal=root->val;
        }
        inorder(root->right,minData,minDif,minDifVal);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr)
            return -1;
        int minData;
        int minDif=INT_MAX;
        int minDifVal=-1;
        minData=root->val;
        inorder(root,minData,minDif,minDifVal);
        return minDifVal;
    }
};
