class Solution {
public:
    
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void util(TreeNode* root,vector<string>& res,string ans)
    {
        ans+=to_string(root->val);
        if(isLeaf(root))
            res.push_back(ans);
        if(root->left)
            util(root->left,res,ans+"->");
        if(root->right)
            util(root->right,res,ans+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans="";
        vector<string> res;
        util(root,res,ans);
        return res;
    }
};
