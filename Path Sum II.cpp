//With backtracing
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


//Without backtracing
class Solution {
public:
    bool isLeaf(TreeNode* node)
    {
        return node->left==nullptr && node->right==nullptr;
    }
    
    void calc(TreeNode* root,int& target,vector<int> temp,vector<vector<int>>& result,int sum)
    {        
        temp.push_back(root->val);
        if(sum==target && isLeaf(root))
            result.push_back(temp);
        if(root->left)
            calc(root->left,target,temp,result,sum+root->left->val);
        if(root->right)
            calc(root->right,target,temp,result,sum+root->right->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        int sum=root->val;
        calc(root,targetSum,temp,result,sum);
        return result;
    }
};
