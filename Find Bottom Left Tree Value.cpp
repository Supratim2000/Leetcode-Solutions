//Method 1(DFS)
class Solution {
public:
    void reverseDfs(TreeNode* root,int level,int& lowestLevel,int& lowestLevelVal)
    {
        if(!root)
            return;
        reverseDfs(root->right,level+1,lowestLevel,lowestLevelVal);
        if(lowestLevel<=level)
        {
            lowestLevel=level;
            lowestLevelVal=root->val;
        }
        reverseDfs(root->left,level+1,lowestLevel,lowestLevelVal);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int lowestLevel=INT_MIN;
        int lowestLevelVal=INT_MIN;
        int rootLevel=0;
        reverseDfs(root,rootLevel,lowestLevel,lowestLevelVal);
        return lowestLevelVal;
    }
};

//Method 2(BFS)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int levelLeftMostVal=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                if(flag)
                {
                    levelLeftMostVal=curNode->val;
                    flag=false;
                }
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            flag=true;
        }
        return levelLeftMostVal;
    }
};
