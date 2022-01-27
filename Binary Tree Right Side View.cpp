//Using DFS
class Solution {
public:
    void traverse(TreeNode *root,int height,int& maxHeightTillNow,vector<int>& view)
    {
        if(root==nullptr)
            return;
        if(height>maxHeightTillNow)
        {
            maxHeightTillNow=height;
            view.push_back(root->val);
        }
        traverse(root->right,height+1,maxHeightTillNow,view);
        traverse(root->left,height+1,maxHeightTillNow,view);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        int maxHeightTillNow=-1;
        if(root==nullptr)
            return view;
        traverse(root,0,maxHeightTillNow,view);
        return view;
    }
};

//Using BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(!root)
            return view;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int n=qu.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=qu.front();
                qu.pop();
                if(i==n-1)
                    view.push_back(curNode->val);
                if(curNode->left)
                    qu.push(curNode->left);
                if(curNode->right)
                    qu.push(curNode->right);
            }
        }
        return view;
    }
};
