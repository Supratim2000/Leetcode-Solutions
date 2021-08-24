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

//Optimised code
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q); 
        if(left && right)
            return root;
        else if(left || right)
        {
            if(root==p)
                return p;
            else if(root==q)
                return q;
            return left?left:right;
        }
        else
        {
            if(root==p)
                return p;
            else if(root==q)
                return q;
            return nullptr;
        }
    }
};
