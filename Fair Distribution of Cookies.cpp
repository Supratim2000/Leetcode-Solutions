class Solution {
public:
    void func(vector<int>& cookies, vector<int>& childrenGet, int j, int& ans)
    {
        if(j==cookies.size())
        {
            int temp=INT_MIN;
            for(int i=0;i<childrenGet.size();i++)
                temp=max(childrenGet[i],temp);
            ans=min(temp,ans);
            return;
        }

        for(int i=0;i<childrenGet.size();i++)
        {
            childrenGet[i]+=cookies[j];
            func(cookies,childrenGet,j+1,ans);
            childrenGet[i]-=cookies[j];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        int n=cookies.size();
        vector<int> childrenGet(k,0);
        func(cookies,childrenGet,0,ans);
        return ans;
    }
};
