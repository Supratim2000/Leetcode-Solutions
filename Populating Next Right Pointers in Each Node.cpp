class Solution {
public:
    
    void dfs(Node* root)
    {
        if(root->left==nullptr && root->right==nullptr)
            return;
        if(root->left)
            root->left->next=root->right;
        if(root->right && root->next)
            root->right->next=root->next->left;
        dfs(root->left);
        dfs(root->right);
    }
    
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
        dfs(root);
        return root;
    }
};
