class Solution {
public:
    TreeNode* arrayToBst(vector<int>& nums,int lb,int hb)
    {
        if(lb>hb)
            return nullptr;
        int mid=lb+(hb-lb)/2;
        TreeNode* root=new TreeNode(nums.at(mid));
        TreeNode* leftSubtree=arrayToBst(nums,lb,mid-1);
        TreeNode* rightSubtree=arrayToBst(nums,mid+1,hb);
        root->left=leftSubtree;
        root->right=rightSubtree;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBst(nums,0,nums.size()-1);
    }
};
