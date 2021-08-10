class Solution {
public:
    pair<int,int> minMaxVal(TreeNode* root,int& maxDif)
    {
        pair<int,int> ans;
        if(root==nullptr)
        {
            ans.first=INT_MAX;
            ans.second=INT_MIN;
        }
        else
        {
            pair<int,int> leftPart=minMaxVal(root->left,maxDif);
            pair<int,int> rightPart=minMaxVal(root->right,maxDif);
            int overallMin=min(root->val,min(leftPart.first,rightPart.first));
            int overallMax=max(root->val,max(leftPart.second,rightPart.second));
            maxDif=max(maxDif,max(abs(root->val-overallMin),abs(root->val-overallMax)));
            ans.first=overallMin;
            ans.second=overallMax;   
        }
        return ans;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDif=INT_MIN;
        minMaxVal(root,maxDif);
        return maxDif;
    }
};
