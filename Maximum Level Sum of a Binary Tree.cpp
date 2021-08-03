//Method 1(Using BFS)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevelSum=INT_MIN;
        int maxSumLevel=INT_MIN;
        int curLevel=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sum=0;
            int n=q.size();
            curLevel++;
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                sum+=curNode->val;
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            if(sum>maxLevelSum)
            {
                maxLevelSum=sum;
                maxSumLevel=curLevel;
            }
        }
        return maxSumLevel;
    }
};

//Method 2(Using DFS)
class Solution {
public:
    void dfs(TreeNode* root,int level,int mxLevelSum,int mxSumLevel,map<int,int>& levelSum)
    {
        if(root==nullptr)
            return;
        levelSum[level]+=root->val;
        dfs(root->left,level+1,mxLevelSum,mxSumLevel,levelSum);
        dfs(root->right,level+1,mxLevelSum,mxSumLevel,levelSum);
    }
    
    int maxLevelSum(TreeNode* root) {
        map<int,int> levelSum;
        int mxLevelSum=INT_MIN;
        int mxSumLevel=INT_MIN;
        int rootLevel=1;
        dfs(root,rootLevel,mxLevelSum,mxSumLevel,levelSum);
        for(auto x: levelSum)
        {
            if(x.second>mxLevelSum)
            {
                mxLevelSum=x.second;
                mxSumLevel=x.first;
            }
        }
        return mxSumLevel;
    }
};
