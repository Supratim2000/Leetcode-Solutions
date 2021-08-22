//Method 1
class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    void traverse(TreeNode* root,int curLevel,int& deepestLevel,TreeNode* curNodePar,unordered_map<TreeNode*,TreeNode*>& parent,vector<TreeNode*>& deepestLeaf)
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
        traverse(root->left,curLevel+1,deepestLevel,root,parent,deepestLeaf);
        traverse(root->right,curLevel+1,deepestLevel,root,parent,deepestLeaf);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(isLeaf(root))
            return root;
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_set<TreeNode*> s;
        vector<TreeNode*> deepestLeaf;
        int deepestLevel=INT_MIN;
        traverse(root,0,deepestLevel,nullptr,parent,deepestLeaf);
        
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

//Method 2
class Solution {
public:
    int height(TreeNode* root,unordered_map<TreeNode*,int>& heightMap)
    {
        if(root==nullptr)
            return 0;
        int lefth=height(root->left,heightMap);
        int righth=height(root->right,heightMap);
        int curDepth=max(lefth,righth)+1;
        heightMap.insert({root,curDepth});
        return curDepth;
    } 
    
    TreeNode* findSmallestSubTree(TreeNode* root,unordered_map<TreeNode*,int>& heightMap)
    {
        if(root==nullptr)
            return nullptr;
        
        int lefth=heightMap[root->left];
        int righth=heightMap[root->right];
        
        if(lefth==righth)
            return root;
        else if(lefth<righth)
            return findSmallestSubTree(root->right,heightMap);
        else
            return findSmallestSubTree(root->left,heightMap);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,int> heightMap;
        heightMap.insert({nullptr,0});
        height(root,heightMap);
        return findSmallestSubTree(root,heightMap); 
    }
};
