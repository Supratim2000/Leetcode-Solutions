class Solution {
public:
    
    void generateParents(TreeNode* root,TreeNode* par,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(!root)
            return;
        parent.insert({root,par});
        generateParents(root->left,root,parent);
        generateParents(root->right,root,parent);    
    }
    
    bool visited(TreeNode* node,unordered_set<TreeNode*>& vis)
    {
        return vis.find(node)!=vis.end();
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> vis;
        generateParents(root,nullptr,parent);
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        if(k==0)
        {
            ans.push_back(q.front()->val);
            return ans;
        }
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                if(curNode->left && !visited(curNode->left,vis))
                {
                    q.push(curNode->left);
                    vis.insert(curNode->left);
                }
                if(curNode->right && !visited(curNode->right,vis))
                {
                    q.push(curNode->right);
                    vis.insert(curNode->right);
                }
                if(parent[curNode] && !visited(parent[curNode],vis))
                {
                    q.push(parent[curNode]);
                    vis.insert(parent[curNode]);
                }
            }
            if(level==k-1)
                break;
            level++;
        }
        
        int n=q.size();
        while(n--)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
