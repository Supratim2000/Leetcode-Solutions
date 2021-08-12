class Solution {
public:
    
    int power(int x, int y)
    {
        int res=1;
        while (y)
        {
            if(y%2==1)
                res=(res*x);
            y=y>>1;
            x=(x*x);
        }
        return res;
    }
    
    int height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void dfs(TreeNode* root,vector<vector<string>>& ans,int row,int minCol,int maxCol)
    {
        if(root==nullptr)
            return;
        int curRow=row;
        int curCol=minCol+((maxCol-minCol)/2);
        ans[curRow][curCol]=to_string(root->val);
        dfs(root->left,ans,row+1,minCol,curCol-1);
        dfs(root->right,ans,row+1,curCol+1,maxCol);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ans;
        int h=height(root);
        int numCol=power(2,h)-1;
        for(int i=0;i<h;i++)
        {
            vector<string> temp(numCol,"");
            ans.push_back(temp);
        }
        int row=0;
        int minCol=0;
        int maxCol=numCol-1;
        dfs(root,ans,row,minCol,maxCol);
        return ans;
    }
};
