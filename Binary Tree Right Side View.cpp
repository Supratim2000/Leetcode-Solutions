class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            bool flag=true;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                if(flag)
                {
                    ans.push_back(curNode->val);
                    flag=false;
                }
                if(curNode->right)
                    q.push(curNode->right);
                if(curNode->left)
                    q.push(curNode->left);
            }
            flag=true;
        }
        return ans;
    }
};
