//Using DFS
void dfs(BinaryTreeNode<int>* root,int level,int& maxLevel)
{
    if(!root)
        return;
    if(level>maxLevel)
    {
        maxLevel=level;
        cout<<root->data<<" ";
    }
    dfs(root->left,level+1,maxLevel);
    dfs(root->right,level+1,maxLevel);
}

void printLeftView(BinaryTreeNode<int> *root)
{
    int maxLevel=-1;
    dfs(root,0,maxLevel);
    cout<<endl;
}

//Using BFS
void printLeftView(BinaryTreeNode<int> *root)
{
	if(!root)
        return;
    queue<BinaryTreeNode<int>*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int n=qu.size();
        for(int i=0;i<n;i++)
        {
            BinaryTreeNode<int>* curNode=qu.front();
            qu.pop();
            if(i==0)
                cout<<curNode->data<<" ";
            if(curNode->left)
                qu.push(curNode->left);
            if(curNode->right)
                qu.push(curNode->right);
        }
    }
}
