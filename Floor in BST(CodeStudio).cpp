int floorInBST(TreeNode<int> * root, int X)
{
    TreeNode<int>* t=root;
    int ans=-1;
    while(t)
    {
        if(t->val==X)
        {
            ans=X;
            break;
        }
        else if(t->val>X)
        	t=t->left;
        else
        {
            ans=t->val;
            t=t->right;
        }
    }
    return ans;
}
