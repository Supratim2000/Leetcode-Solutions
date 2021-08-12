class Solution {
public:    
    void dfs(TreeNode* root,int curLevel,int parent,int& x,int& y,pair<int,int>& ff,pair<int,int>& ss)
    {
        if(root==nullptr)
            return;
        if(root->val==x)
        {
            ff.first=curLevel;
            ff.second=parent;
        }
        if(root->val==y)
        {
            ss.first=curLevel;
            ss.second=parent;
        }
        dfs(root->left,curLevel+1,root->val,x,y,ff,ss);
        dfs(root->right,curLevel+1,root->val,x,y,ff,ss);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> ff;
        pair<int,int> ss;
        dfs(root,0,-1,x,y,ff,ss);
        if(ss.first==ff.first && ss.second!=ff.second)
            return true;
        return false;
    }
};
