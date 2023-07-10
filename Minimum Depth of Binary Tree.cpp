class Solution {
public:
    //Method 1
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(root->left && !root->right)
            return 1+minDepth(root->left);
        else if(!root->left && root->right)
            return 1+minDepth(root->right);
        else
        {
            int leftSubTreeMinDepth=minDepth(root->left);
            int rightSubTreeMinDepth=minDepth(root->right);
            return 1+min(leftSubTreeMinDepth,rightSubTreeMinDepth);
        }
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
