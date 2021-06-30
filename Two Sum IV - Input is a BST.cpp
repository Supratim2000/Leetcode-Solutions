class Solution {
public:
    
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
};
