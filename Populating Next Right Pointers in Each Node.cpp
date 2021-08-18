//Method 1 (RECURSIVE)
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

//Method 2 (ITERATIVE)
class Solution {
public:
    
    bool isLeaf(Node* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    Node* connectNodes(Node* root)
    {
        root->left->next=root->right;
        root->right->next=nullptr;
        Node* cur=root->left;
        Node* start=root->left;
        while(cur)
        {
            while(cur)
            {
                if(cur->left)
                    cur->left->next=cur->right;
                if(cur->right && cur->next)
                    cur->right->next=cur->next->left;
                cur=cur->next;
            }
            start=start->left;
            cur=start;
        }
        return root;
    }
    
    Node* connect(Node* root) {
        if(root==nullptr || isLeaf(root))
            return root;
        return connectNodes(root);
    }
};
