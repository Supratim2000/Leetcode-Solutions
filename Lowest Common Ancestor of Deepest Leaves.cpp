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
    
    TreeNode* findLca(TreeNode* root,unordered_map<TreeNode*,int>& heightMap)
    {
        if(root==nullptr)
            return nullptr;
        
        int lefth=heightMap[root->left];
        int righth=heightMap[root->right];
        
        if(lefth==righth)
            return root;
        else if(lefth<righth)
            return findLca(root->right,heightMap);
        else
            return findLca(root->left,heightMap);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,int> heightMap;
        heightMap.insert({nullptr,0});
        height(root,heightMap);
        return findLca(root,heightMap);
    }
};
