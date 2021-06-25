class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            int n=pendingNodes.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=pendingNodes.front();
                temp.push_back(curNode->val);
                pendingNodes.pop();
                if(curNode->left!=nullptr)
                    pendingNodes.push(curNode->left);
                if(curNode->right!=nullptr)
                    pendingNodes.push(curNode->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
