class Solution {
public:
    //Method 1
    void helper(TreeNode* root,vector<int>& arr)
    {
        if(root==nullptr)
            return;
        helper(root->left,arr);
        arr.push_back(root->val);
        helper(root->right,arr);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        helper(root,arr);
        
        int low=0;
        int high=arr.size()-1;
        
        while(low<high)
        {
            if(arr.at(low)==k-arr.at(high))
                return true;
            else if(arr.at(low)<k-arr.at(high))
                low++;
            else
                high--;
        }
        return false;
    }
    
    void dfs(TreeNode* root, unordered_set<int>& pres, int& k, bool& isPresent)
    {
        if(root==nullptr)
            return ;
        dfs(root->left,pres,k,isPresent);
        dfs(root->right,pres,k,isPresent);
        if(pres.find(k-root->val)==pres.end())
            pres.insert(root->val);
        else
        {
            isPresent=true;
            return;
        }
    }
    
    //Method 2
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> pres;
        bool isPresent=false;
        dfs(root,pres,k,isPresent);
        return isPresent;
    }
    
};
