class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void calc(TreeNode* root,int target,vector<int>& temp,vector<vector<int>>& result)
    {
        if(root==nullptr)
            return;
        if(root->val==target && isLeaf(root))
        {
            temp.push_back(root->val);
            result.push_back(temp);
            temp.pop_back();
        }
        temp.push_back(root->val);
        calc(root->left,target-root->val,temp,result);
        calc(root->right,target-root->val,temp,result);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> result;
        calc(root,targetSum,temp,result);
        return result;
    }
};
