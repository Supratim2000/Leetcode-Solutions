class Solution {
public:
    void inorder(TreeNode* root,vector<int>& sorted)
    {
        if(!root)
            return;
        inorder(root->left,sorted);
        sorted.push_back(root->val);
        inorder(root->right,sorted);
    }
    
    TreeNode* createBST(vector<int>& sorted,int low,int high)
    {
        if(low>high)
            return nullptr;
        int mid=low+(high-low)/2;
        int rootVal=sorted.at(mid);
        TreeNode* root=new TreeNode(rootVal);
        TreeNode* leftPart=createBST(sorted,low,mid-1);
        TreeNode* rightPart=createBST(sorted,mid+1,high);
        root->left=leftPart;
        root->right=rightPart;
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root,sorted);
        int lowerBound=0;
        int heigherBound=sorted.size()-1;
        return createBST(sorted,lowerBound,heigherBound);
    }
};
