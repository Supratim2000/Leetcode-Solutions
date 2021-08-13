class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void dfs(TreeNode* root,string& treeRep)
    {
        if(isLeaf(root))
        {
            treeRep+=to_string(root->val);
            treeRep+=")";
            return;
        }
        treeRep+=to_string(root->val);
        if(root->left)
        {
            treeRep+="(";
            dfs(root->left,treeRep);
        }
        else
            treeRep+="()";
        if(root->right)
        {
            treeRep+="(";
            dfs(root->right,treeRep);
        }
        treeRep+=")";
    }
    
    string tree2str(TreeNode* root) {
        string treeRep="";
        dfs(root,treeRep);
        treeRep.pop_back();
        return treeRep;
    }
};
