class Solution {
public:
    void inorder(TreeNode* root,vector<int>& mode,int& maxCount,int& count,int& prev)
    {
        if(root==nullptr)
            return;
        
        inorder(root->left,mode,maxCount,count,prev);
        
        if(prev==-1)
            mode.push_back(root->val);
        else
        {
            root->val==prev?count++:count=0;
            if(count>maxCount)
            {
                maxCount=count;
                mode.clear();
                mode.push_back(root->val);
            }
            else if(count==maxCount)
                mode.push_back(root->val);
        }
        prev=root->val;
        
        inorder(root->right,mode,maxCount,count,prev);
    }
    
    vector<int> findMode(TreeNode* root) {
        int maxCount=0;
        int count=0;
        int prev=-1;
        vector<int> mode;
        inorder(root,mode,maxCount,count,prev);
        return mode;
    }
};
