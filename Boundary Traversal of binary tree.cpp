class Solution {
public:
    void leftBound(Node* root, vector<int>& ans, Node* realRoot)
    {
        if(!root)
            return;
        if(!realRoot->left)
        {
            ans.push_back(root->data);
            return;
        }
        if(!root->left && !root->right)
            return;
        ans.push_back(root->data);
        if(root->left)
            leftBound(root->left,ans,realRoot);
        else
            leftBound(root->right,ans,realRoot);
    }
    
    void appendLeaf(Node* root, vector<int>& ans, Node* &lastLeafRef)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            lastLeafRef=root;
            ans.push_back(root->data);
        }
        appendLeaf(root->left, ans, lastLeafRef);
        appendLeaf(root->right, ans, lastLeafRef);
    }
    
    void rightBound(Node* root, vector<int>& ans, Node* lastLeafRef, Node* realRoot)
    {
        if(!root)
            return;
        if(!realRoot->right)
            return;
        if(root->right)
            rightBound(root->right,ans,lastLeafRef,realRoot);
        else
            rightBound(root->left,ans,lastLeafRef,realRoot);
        if(root!=realRoot && root!=lastLeafRef)
            ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        Node* lastLeafRef=nullptr;
        if(!root)
            return ans;
        leftBound(root, ans, root);
        appendLeaf(root, ans, lastLeafRef);
        rightBound(root, ans, lastLeafRef, root);
        
        return ans;
    }
};
