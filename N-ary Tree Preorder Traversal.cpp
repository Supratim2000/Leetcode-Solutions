class Solution {
public:
    
    void preOrder(Node* root,vector<int>& ans)
    {
        if(root==nullptr)
            return;
        ans.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
            preOrder(root->children.at(i),ans);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        preOrder(root,ans);
        return ans;
    }
};
