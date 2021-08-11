class Solution {
public:    
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void dfs(TreeNode* root,string ans,string& prev,string& cur)
    {
        ans+=(char)('a'+root->val);
        if(isLeaf(root))
        {
            reverse(ans.begin(),ans.end());
            if(prev.empty())
                prev=ans;
            else
            {
                prev<ans?cur=prev:cur=ans;
                prev=cur;
            }
        }
        if(root->left)
            dfs(root->left,ans,prev,cur);
        if(root->right)
            dfs(root->right,ans,prev,cur);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string prev="";
        string cur="";
        for(int i=0;i<8501;i++)
            prev+='z';
        if(isLeaf(root))
        {
            ans=(char)('a'+root->val);
            return ans;
        }
        dfs(root,ans,prev,cur);
        if(cur.empty())
            return prev;
        return cur;
    }
};
