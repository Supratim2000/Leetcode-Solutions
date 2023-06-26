class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        string ans="";
        int size=K;
        int dictSize=N;
        vector<int> adj[size];
        for(int i=0;i<dictSize-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            for(int j=0;j<min(s1.size(),s2.size());j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        //Topological sorting
        queue<int> q;
        vector<int> indeg(size,0);
        for(auto x: adj)
            for(auto y: x)
                indeg[y]++;
        
        for(int i=0;i<size;i++)
            if(indeg[i]==0)
                q.push(i);
        
        while(!q.empty())
        {
            int curNode=q.front();
            ans.push_back((char)(curNode+'a'));
            q.pop();
            for(auto adjNode: adj[curNode])
            {
                indeg[adjNode]--;
                if(indeg[adjNode]==0)
                    q.push(adjNode);
            }
        }
        
        return ans;
    }
};
