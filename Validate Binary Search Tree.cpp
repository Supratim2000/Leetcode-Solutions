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
    typedef long long ll;
    void fun(TreeNode* root,ll min,ll max,bool& ans)
    {
        if(root==nullptr)
            return;
        fun(root->left,min,(ll)root->val-1,ans);
        if(root->val<min || root->val>max)
        {
            ans=false;
            return;
        }
        fun(root->right,(ll)root->val+1,max,ans);
    }
    
    bool isValidBST(TreeNode* root) {
        
        bool ans=true;
        ll max=INT_MAX,min=INT_MIN;
        fun(root,min,max,ans);
        return ans;
    }
};
