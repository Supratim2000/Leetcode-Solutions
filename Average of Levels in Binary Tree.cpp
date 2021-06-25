
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            double avg=0;
            int n=pendingNodes.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=pendingNodes.front();
                avg+=curNode->val;
                pendingNodes.pop();
                if(curNode->left!=nullptr)
                    pendingNodes.push(curNode->left);
                if(curNode->right!=nullptr)
                    pendingNodes.push(curNode->right);
            }
            res.push_back(avg/n);
        }
        return res;
    }
};
