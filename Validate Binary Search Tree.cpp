//Method 1
class Solution {
public:
    void inorder(TreeNode* root,bool& ans,bool& f_time,int& prev_val)
    {
        if(root==nullptr)
            return;
        inorder(root->left,ans,f_time,prev_val);
        if(f_time)
        {
            f_time=false;
            prev_val=root->val;
        }
        else
        {
            int cur_val=root->val;
            if(cur_val<=prev_val)
            {
                ans=false;
                return;
            }
            prev_val=cur_val;      
        }
        inorder(root->right,ans,f_time,prev_val);
    }
    
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        bool f_time=true;
        int prev_val=-1;
        inorder(root,ans,f_time,prev_val);
        return ans;
    }
};

//Method 2
class Solution {
public: 
    void validate(TreeNode* root, long long min, long long max, bool& isBst)
    {
        if(!root)
            return;
        if(root->val>max || root->val<min)
        {
            isBst=false;
            return;
        }
        if(isBst)
            validate(root->left,min,(long long)root->val-1,isBst);
        if(isBst)
            validate(root->right,(long long)root->val+1,max,isBst);
    }
    bool isValidBST(TreeNode* root) {
        bool isBst=true;
        validate(root,LLONG_MIN,LLONG_MAX,isBst);
        return isBst;
    }
};
