//My approach 1
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


//My approach 2
class Solution {
public:
    void bfs(int src, vector<int> adj[], vector<int>& vis)
    {
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            for(auto x: adj[curNode])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parentCount(n,0);
        vector<int> adj[n];
        vector<int> vis(n,false);
        int numOfComponent=0;
        int numOne=0;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                adj[i].push_back(leftChild[i]);
                adj[leftChild[i]].push_back(i);
                parentCount[leftChild[i]]++;
            }
            if(rightChild[i]!=-1)
            {
                adj[i].push_back(rightChild[i]);
                adj[rightChild[i]].push_back(i);
                parentCount[rightChild[i]]++;
            }
        }            
        for(int i=0;i<n;i++)
            if(parentCount[i]==1)
                numOne++;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                numOfComponent++;
                bfs(i,adj,vis);
            }
        }
        return (numOfComponent>1 || numOne!=n-1)?false:true;
    }
};
