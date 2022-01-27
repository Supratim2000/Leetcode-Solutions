void bfs(BinaryTreeNode<int>* root,map<int,int>& mp)
{
    if(!root)
        return;
    queue<pair<BinaryTreeNode<int>*,int>> qu;
    qu.push({root,0});
    while(!qu.empty())
    {
        int n=qu.size();
        for(int i=0;i<n;i++)
        {
            pair<BinaryTreeNode<int>*,int> curNode=qu.front();
            qu.pop();
                mp[curNode.second]=curNode.first->data;
            if(curNode.first->left)
                qu.push({curNode.first->left,curNode.second-1});
            if(curNode.first->right)
                qu.push({curNode.first->right,curNode.second+1});
        }
    }
}

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    map<int,int> mp; //spread,data
    bfs(root,mp);
    for(auto x: mp)
        ans.push_back(x.second);
    return ans;
}
