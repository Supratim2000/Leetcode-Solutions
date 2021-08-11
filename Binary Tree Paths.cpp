class Solution {
public:
    
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void helper(TreeNode* root,string ans,vector<string>& res)
    {
        if(root==nullptr)
            return;
        if(isLeaf(root))
        {
            ans+=to_string(root->val);
            res.push_back(ans);
            ans="";
        }
        ans+=to_string(root->val)+"->";
        helper(root->left,ans,res);
        helper(root->right,ans,res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans="";
        vector<string> res;
        if(isLeaf(root))
        {
            ans+=to_string(root->val);
            res.push_back(ans);
            return res;
        }
        else
            helper(root,ans,res);
        return res;
    }
};
