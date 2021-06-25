class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==nullptr)
            return arr;
        queue<vector<TreeNode*>> pendingNodes;
        vector<TreeNode*> temp;
        temp.push_back(root);
        pendingNodes.push(temp);
        while(!pendingNodes.empty())
        {
            vector<TreeNode*> tp=pendingNodes.front();
            vector<int> x;
            for(int i=0;i<tp.size();i++)
                x.push_back(tp.at(i)->val);
            arr.push_back(x);
            pendingNodes.pop();
            vector<TreeNode*> ans;
            for(int i=0;i<tp.size();i++)
            {
                TreeNode* cur=tp.at(i);
                if(cur->left != nullptr)
                    ans.push_back(cur->left);
                if(cur->right != nullptr)
                    ans.push_back(cur->right);
            }
            if(!ans.empty())
                pendingNodes.push(ans);
        }
        return arr;   
    }
};
