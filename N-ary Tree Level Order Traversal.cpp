class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++)
            {
                Node* curNode=q.front();
                q.pop();
                level.push_back(curNode->val);
                for(int i=0;i<curNode->children.size();i++)
                    q.push(curNode->children.at(i));
            }
            ans.push_back(level);
        }
        return ans;
    }
};
