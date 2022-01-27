void dfs(BinaryTreeNode<int>* root,int level,int& maxLevel,vector<int>& view)
{
    if(!root)
        return;
    if(level>maxLevel)
    {
        maxLevel=level;
        view.push_back(root->data);
    }
    dfs(root->left,level+1,maxLevel,view);
    dfs(root->right,level+1,maxLevel,view);
}

void printLeftView(BinaryTreeNode<int> *root)
{
	vector<int> view;
	int maxLevel=-1;
    dfs(root,0,maxLevel,view);
    for(auto x: view)
        cout<<x<<" ";
    cout<<endl;
}
