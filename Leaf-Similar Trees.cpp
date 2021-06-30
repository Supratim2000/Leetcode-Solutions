class Solution {
public:
    
    void traversal(TreeNode* root, vector<int>& leaf)
    {
        if(root==nullptr)
            return;
        traversal(root->left, leaf);
        if(root->left==nullptr && root->right==nullptr)
            leaf.push_back(root->val);
        traversal(root->right, leaf);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        traversal(root1,leaf1);
        traversal(root2,leaf2);
        if(leaf1.size()!=leaf2.size())
            return false;
        for(int i=0;i<leaf1.size();i++)
        {
            if(leaf1.at(i)!=leaf2.at(i))
                return false;
        }
        return true;
    }
};
