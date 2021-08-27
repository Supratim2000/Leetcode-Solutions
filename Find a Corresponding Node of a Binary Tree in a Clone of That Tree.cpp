//If values are uniqueue in tree
class Solution {
public:
    
    TreeNode* ans=nullptr;
    
    void dfs(TreeNode* cloned, int target_val)
    {
        if(cloned==nullptr)
            return ;
        dfs(cloned->left,target_val);
        if(cloned->val==target_val)
        {
            ans=cloned;
            return;
        }
        dfs(cloned->right,target_val);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int target_val=target->val;
        dfs(cloned,target_val);
        return ans;
    }
};


//If values are repeated in tree
class Solution {
public:
    TreeNode* ans=nullptr;
    void dfs(TreeNode* original,TreeNode* cloned,TreeNode* target)
    {
        if(cloned==nullptr)
            return ;
        dfs(original->left,cloned->left,target);
        if(target==original)
        {
            ans=cloned;
            return;
        }
        dfs(original->right,cloned->right,target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned,target);
        return ans;
    }
};

//BFS Solution
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({original,cloned});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                pair<TreeNode*,TreeNode*> curNodes=q.front();
                q.pop();
                if(curNodes.first==target)
                    return curNodes.second;
                if(curNodes.first->left)
                    q.push({curNodes.first->left,curNodes.second->left});
                if(curNodes.first->right)
                    q.push({curNodes.first->right,curNodes.second->right});
            }
        }
        return nullptr;
    }
};

//Finding path in original tree using DFS and then going to the node in cloned tree
class Solution {
public:
    void dfs(TreeNode* original,TreeNode* target,string path,string& targetPath)
    {
        if(!original)
            return;
        if(target==original)
        {
            targetPath=path;
            return;
        }
        dfs(original->left,target,path+"l",targetPath);
        dfs(original->right,target,path+"r",targetPath);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        string targetPath="";
        dfs(original,target,"",targetPath);
        TreeNode* ref=cloned;
        for(int i=0;i<targetPath.size();i++)
            targetPath[i]=='l'?ref=ref->left:ref=ref->right;
        return ref;
    }
};
