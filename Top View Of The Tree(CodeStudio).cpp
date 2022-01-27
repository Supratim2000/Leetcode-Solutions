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
