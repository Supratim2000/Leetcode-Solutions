//My approach(Not much optimised)
class Solution {
public:
    void parentGenerator(TreeNode* root,TreeNode* parent,int level,unordered_map<TreeNode*,TreeNode*>& parentMap,TreeNode* p,TreeNode* q,int& pLevel,int& qLevel)
    {
        if(!root)
            return;
        parentMap.insert({root,parent});
        if(root==p)
            pLevel=level;
        if(root==q)
            qLevel=level;
        parentGenerator(root->left,root,level+1,parentMap,p,q,pLevel,qLevel);
        parentGenerator(root->right,root,level+1,parentMap,p,q,pLevel,qLevel);     
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pLevel=-1;
        int qLevel=-1;
        unordered_map<TreeNode*,TreeNode*> parentMap;
        parentGenerator(root,nullptr,1,parentMap,p,q,pLevel,qLevel);
        if(pLevel>qLevel)
            while(pLevel--!=qLevel)
                p=parentMap[p];
        else if(pLevel<qLevel)
            while(qLevel--!=pLevel)
                q=parentMap[q];
        while(p!=q)
        {
            p=parentMap[p];
            q=parentMap[q];
        }
        return p;
    }
};

//Bit optimised approach
class Solution {
public:
    void rootToNodePath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& hasPath)
    {
        if(!root)
            return ;
        if(!hasPath)
            path.push_back(root);
        if(root==target)
        {
            hasPath=true;
            return;
        }
        rootToNodePath(root->left, target, path, hasPath);
        rootToNodePath(root->right, target, path, hasPath);
        if(!hasPath)
            path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ansNode=nullptr;
        bool hasPathP=false;
        bool hasPathQ=false;
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        rootToNodePath(root,p,path_p,hasPathP);
        rootToNodePath(root,q,path_q,hasPathQ);
        for(int i=0;i<min(path_p.size(), path_q.size());i++)
        {
            if(path_p.at(i)==path_q.at(i))
                ansNode=path_p.at(i);
            else
                break;
        }
        return ansNode;
    }
};

//Optimised code
class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        if(left && right)
            return root;
        else if(root==p)
            return p;
        else if(root==q)
            return q;
        else if(left || right)
            return left?left:right;
        else
            return nullptr;
    }
};
