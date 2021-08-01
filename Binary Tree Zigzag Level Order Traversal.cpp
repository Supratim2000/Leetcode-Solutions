class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool toggle=true;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                level.push_back(curNode->val);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            if(!toggle)
            {
                int l=0;
                int h=level.size()-1;
                while(l<h)
                    swap(level.at(l++),level.at(h--));
                    
            }
            ans.push_back(level);
            toggle=!toggle;
            level.clear();
        }
        return ans;
    }
};
