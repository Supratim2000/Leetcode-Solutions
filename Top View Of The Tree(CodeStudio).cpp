//Using BFS(Recursive)
#include<map>

void dfs(TreeNode<int> *root,int spread,int level,map<int,pair<int,int>>& mp)
{
    if(!root)
        return;
    else if(mp.find(spread)==mp.end())
        mp.insert({spread,{level,root->val}});
    else if(mp[spread].first>level)
    {
        mp[spread].first=level;
        mp[spread].second=root->val;
    }
    dfs(root->left,spread-1,level+1,mp);
    dfs(root->right,spread+1,level+1,mp);
}

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    map<int,pair<int,int>> mp; //spread,level,data
    dfs(root,0,0,mp);
    for(auto x: mp)
        ans.push_back(x.second.second);
    return ans;
}


//Using BFS(Iterative)
#include<map>

void bfs(TreeNode<int> *root,map<int,int>& mp)
{
    if(!root)
        return;
    queue<pair<TreeNode<int>* ,int>> qu;
    qu.push({root,0});
    while(!qu.empty())
    {
        int n=qu.size();
        for(int i=0;i<n;i++)
        {
            pair<TreeNode<int>*,int> curNode=qu.front();
            qu.pop();
            if(mp.find(curNode.second)==mp.end())
                mp.insert({curNode.second,curNode.first->val});
            if(curNode.first->left)
                qu.push({curNode.first->left,curNode.second-1});
            if(curNode.first->right)
                qu.push({curNode.first->right,curNode.second+1});
        }
    }
}

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    map<int,int> mp; //spread,data
    bfs(root,mp);
    for(auto x: mp)
        ans.push_back(x.second);
    return ans;
}
