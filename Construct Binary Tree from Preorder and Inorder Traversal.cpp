class Solution {
public:
    int searchRootDataIndex(vector<int>& inorder,vector<int>& preorder, int preLow, int preHigh, int inLow,int inHigh)
    {
        int rootData=preorder.at(preLow);
        for(int i=inLow;i<=inHigh;i++)
        {
            if(inorder.at(i)==rootData)
                return i;
        }
        return -1;
    }

    TreeNode* createTree(vector<int>& inorder, vector<int>& preorder, int preLow, int preHigh, int inLow, int inHigh)
    {
        if((inHigh<inLow) || (preHigh<preLow))
            return nullptr;

        int rootDataIndex=searchRootDataIndex(inorder,preorder,preLow,preHigh,inLow,inHigh);
        
        int lInS=inLow;
        int lInE=rootDataIndex-1;
        int rInS=rootDataIndex+1;
        int rInE=inHigh;
        int lPreS=preLow+1;
        int lPreE=lInE-lInS+lPreS;
        int rPreS=lPreE+1;
        int rPreE=preHigh;
        
        TreeNode* root=new TreeNode(inorder.at(rootDataIndex));

        TreeNode* leftPart=createTree(inorder,preorder,lPreS,lPreE,lInS,lInE);
        TreeNode* rightPart=createTree(inorder,preorder,rPreS,rPreE,rInS,rInE);
        
        root->left=leftPart;
        root->right=rightPart;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(inorder,preorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
