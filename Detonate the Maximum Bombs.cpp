class Solution {
public:
    bool isBlast(vector<int>& a,vector<int>& b)
    {
        long long x1=a[0];
        long long x2=b[0];
        long long y1=a[1];
        long long y2=b[1];
        long long r=a[2];
        long long x=(x1-x2)*(x1-x2);
        long long y=(y1-y2)*(y1-y2);
        return x+y<=r*r;
    }
    
    void dfs(vector<vector<int>>& bombs,vector<bool>& vis, int n, int j, int& count)
    {
        vis[j]=true;
        count++;
        for(int i=0;i<n;i++)
            if(i!=j)
                if(isBlast(bombs[j],bombs[i]) && !vis[i])
                    dfs(bombs,vis,n,i,count);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        int maxNum=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<bool> vis(n,false);
            dfs(bombs,vis,n,i,count);
            maxNum=max(maxNum,count);
        }
        return maxNum;
    }
};
