int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int>* t=node;
    int ans=-1;
	while(t)
    {
        if(t->data==x)
        {
            ans=t->data;
            break;
        }
        else if(t->data>x)
        {
            ans=t->data;
            t=t->left;
        }
        else
            t=t->right;
    }
    return ans;
}
