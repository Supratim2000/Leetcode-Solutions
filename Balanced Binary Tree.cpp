//Unoptimised O(n^2)
class Solution {
public:
    
    int height(TreeNode* root)
    {
        return !root?0:max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool left=isBalanced(root->left);
        if(!left) return false;
        bool right=isBalanced(root->right);
        if(!right) return false;
        return left && right && abs(height(root->left)-height(root->right))<=1;
    }
};

//Optimised O(n)
class Solution {
public:    
    int height(TreeNode* root,bool &balanced)
    {
        if(root==nullptr)
            return 0;
        int leftHeight=height(root->left,balanced);
        int rightHeight=height(root->right,balanced);
        if(abs(leftHeight-rightHeight)>1)
        {
            balanced=false;
            return 10000;
        }
        return max(leftHeight,rightHeight)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        height(root,balanced);
        return balanced;
    }
};

//Optimised O(n) with a function which returns both height and isHieghtBalanced simultaniously in pair
class Solution {
public:    
    pair<int,bool> treeBalanced(TreeNode* root)
    {
        pair<int,bool> ans;
        if(root==nullptr)
        {
            ans.first=0;
            ans.second=true;
        }
        else if(root->left==nullptr && root->right==nullptr)
        {
            ans.first=1;
            ans.second=true;
        }
        else if(root->left==nullptr && root->right!=nullptr)
        {
            pair<int,bool> right=treeBalanced(root->right);
            ans.second=(right.second && right.first==1);
            ans.first=right.first+1;
        }
        else if(root->left!=nullptr && root->right==nullptr)
        {   
            pair<int,bool> left=treeBalanced(root->left);
            ans.second=(left.second && left.first==1);
            ans.first=left.first+1;
        }
        else
        {
            pair<int,bool> left=treeBalanced(root->left);
            pair<int,bool> right=treeBalanced(root->right);
            ans.second=(left.second && right.second && abs(left.first-right.first)<=1);            
            ans.first=max(left.first,right.first)+1;
        }
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=treeBalanced(root);
        return ans.second;
    }  
};
