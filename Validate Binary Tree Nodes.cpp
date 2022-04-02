//My approach
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root=-1;
        int count=0;
        vector<int> adj[n];
        vector<int> indeg(n,0);
        vector<bool> vis(n,false);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                adj[i].push_back(leftChild[i]);
                indeg[leftChild[i]]++;
            }
            if(rightChild[i]!=-1)
            {
                adj[i].push_back(rightChild[i]);
                indeg[rightChild[i]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!indeg[i])
            {
                count++;
                root=i;
            }
        }
        if(count>1 || root==-1)
            return false;
        q.push(root);
        vis[root]=true;
        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            for(auto x: adj[curNode])
            {
                if(vis[x])
                    return false;
                q.push(x);
                vis[x]=true;
            }
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                return false;
        return true;
    }
};
