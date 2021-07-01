class Solution {
public:
    //Method 1
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr && root->right==nullptr)
            return 1;
        if(root->left==nullptr)
            return minDepth(root->right)+1;
        if(root->right==nullptr)
            return minDepth(root->left)+1;
        return min(minDepth(root->right),minDepth(root->left))+1;
    }
        
    //Method 2
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        int level=1;
        while(!pendingNodes.empty())
        {
            int n=pendingNodes.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* cur=pendingNodes.front();
                pendingNodes.pop();
                if(cur->left==nullptr && cur->right==nullptr)
                    return level;
                if(cur->left!=nullptr)
                    pendingNodes.push(cur->left);
                if(cur->right!=nullptr)
                    pendingNodes.push(cur->right);
            }
            level++;
        }
        return level;
    }
};
