class Solution {
public:
    TreeNode* create(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& hash, int is, int ie, int ps, int pe)
    {
        if(is>ie || ps>pe)
            return nullptr;
        int rootIndxInInorder=hash[postorder[pe]];
        int lps=ps;
        int lpe=lps+rootIndxInInorder-is-1;
        int lis=is;
        int lie=rootIndxInInorder-1;
        int rps=lpe+1;
        int rpe=pe-1;
        int ris=rootIndxInInorder+1;
        int rie=ie;
        TreeNode* root=new TreeNode(postorder[pe]);
        root->left=create(inorder,postorder,hash,lis,lie,lps,lpe);
        root->right=create(inorder,postorder,hash,ris,rie,rps,rpe);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++)
            hash[inorder[i]]=i;
        return create(inorder,postorder,hash,0,n-1,0,n-1);
    }
};
