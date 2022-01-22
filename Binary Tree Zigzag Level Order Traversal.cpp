//Method-1 (By reversing vector)
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

//Method-2 (Without reversing vector)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        bool toggle=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                int index=i;
                if(toggle)
                    index=n-i-1;
                level[index]=curNode->val;
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            ans.push_back(level);
            toggle=!toggle;
        }
        return ans;
    }
};
