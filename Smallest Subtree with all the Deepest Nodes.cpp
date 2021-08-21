//Method 1
class Solution {
public:
    
    int deepestLevel=INT_MIN;
    
    bool isLeaf(TreeNode* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    void traverse(TreeNode* root,int curLevel,TreeNode* curNodePar,unordered_map<TreeNode*,TreeNode*>& parent,vector<TreeNode*>& deepestLeaf)
    {
        if(root==nullptr)
            return;
        
        parent.insert({root,curNodePar});
        
        
        if(curLevel>=deepestLevel)
        {
            if(curLevel>deepestLevel)
                deepestLeaf.clear();
            deepestLeaf.push_back(root);
            deepestLevel=curLevel;
        }
        
        
        traverse(root->left,curLevel+1,root,parent,deepestLeaf);
        traverse(root->right,curLevel+1,root,parent,deepestLeaf);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(isLeaf(root))
            return root;
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> s;
        vector<TreeNode*> deepestLeaf;
        traverse(root,0,nullptr,parent,deepestLeaf);
        
        if(deepestLeaf.size()==1)
            return deepestLeaf[0];
        
        while(s.size()!=1)
        {
            s.clear();
            for(int i=0;i<deepestLeaf.size();i++)
            {
                deepestLeaf[i]=parent[deepestLeaf[i]];
                cout<<deepestLeaf[i]->val<<" ";
                s.insert(deepestLeaf[i]);
            }
            cout<<endl;
        }
        return *s.begin(); 
    }
};

//Method 2(todo)
