class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> levelMax;
        if(root==nullptr)
            return levelMax;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int maxInRow=INT_MIN;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                maxInRow=max(maxInRow,curNode->val);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            levelMax.push_back(maxInRow);
            maxInRow=INT_MIN;
        }
        return levelMax;
    }
};
