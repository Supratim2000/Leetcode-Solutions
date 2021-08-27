//Method 1(DFS)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int count=0;
        if(root==nullptr)
            return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            int n=pendingNodes.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=pendingNodes.front();
                pendingNodes.pop();
                sum+=curNode->val;
                if(curNode->left!=nullptr)
                {
                    pendingNodes.push(curNode->left);
                    count++;
                }
                if(curNode->right!=nullptr)
                {
                    pendingNodes.push(curNode->right);
                    count++;
                }
            }
            if(count==0)
                break;
            count=0;
            sum=0;

        }
        return sum;        
    }
};


//Method 2(DFS One pass)
class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        return !root->left && !root->right;
    }
    
    void dfs(TreeNode* root,int level,int& maxDepth, int& sum)
    {
        if(!root)
            return;
        if(isLeaf(root))
        {
            if(level>=maxDepth)
            {
                if(level==maxDepth)
                    sum+=root->val;
                else
                    sum=root->val;
                maxDepth=level;
            }
        }    
        dfs(root->left,level+1,maxDepth,sum);
        dfs(root->right,level+1,maxDepth,sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=-1;
        int sum=0;
        int rootLevel=1;
        dfs(root,rootLevel,maxDepth,sum);  
        return sum;
    }
};


//Method 3(DFS Two pass)
class Solution {
public:
    int height(TreeNode* root)
    {
        return !root?0:1+max(height(root->left),height(root->right));
    }
    
    void dfs(TreeNode* root,int level,int& h,int& sum)
    {
        if(!root)
            return;
        if(level==h)
            sum+=root->val;
        dfs(root->left,level+1,h,sum);
        dfs(root->right,level+1,h,sum);    
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int h=height(root);
        dfs(root,1,h,sum);  
        return sum;
    }
};
