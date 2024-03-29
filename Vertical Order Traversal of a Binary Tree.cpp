class Solution {
public:
    void dfs(TreeNode* root,int row ,int col, map<int, map<int, multiset<int>>>& mp)
    {
        if(!root)
            return;
        mp[col][row].insert(root->val);
        dfs(root->left,row+1,col-1,mp);
        dfs(root->right,row+1,col+1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        dfs(root,0,0,mp);
        for(auto x: mp)
        {
            vector<int> temp;
            for(auto y: x.second)
                for(auto z: y.second)
                    temp.push_back(z);
            ans.push_back(temp);
        }
        return ans;
    }
};
