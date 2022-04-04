class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        if(nums[0]==0)
            pre[0]=1;
        if(nums[n-1]==1)
            suf[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)
                pre[i]=pre[i-1]+1;
            else
                pre[i]=pre[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==1)
                suf[i]=suf[i+1]+1;
            else
                suf[i]=suf[i+1];
        }
        int maxVal=-1;
        
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                maxVal=max(maxVal,pre[i]);
            }
            else
            {
                int s=pre[i]+suf[i+1];
                maxVal=max(maxVal,s);
            }
        }
        maxVal=max(maxVal,suf[0]);
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                if(pre[i]==maxVal)
                    ans.push_back(n);
            }
            else
            {
                int s=pre[i]+suf[i+1];
                if(s==maxVal)
                {
                    ans.push_back(i+1);
                }
            }
        }   
        if(suf[0]==maxVal)
            ans.push_back(0);       
        return ans;
    }
};
