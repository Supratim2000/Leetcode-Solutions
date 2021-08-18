typedef long long ll;
class Solution {
public:
    ll maxProductInTree=LLONG_MIN;
    ll mod=1000000007;
    
    ll sumOfTree(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        return root->val+sumOfTree(root->left)+sumOfTree(root->right);
    }
    
    ll subTreeSum(TreeNode* root,ll wholeTreeSum)
    {
        if(root==nullptr)
            return 0;
        ll l=subTreeSum(root->left,wholeTreeSum);
        ll r=subTreeSum(root->right,wholeTreeSum);
        maxProductInTree=max(maxProductInTree,max((wholeTreeSum-l)*l,(wholeTreeSum-r)*r));
        return l+r+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        ll treeSum=sumOfTree(root);
        subTreeSum(root,treeSum);
        return (int)(maxProductInTree%mod);
    }
};
