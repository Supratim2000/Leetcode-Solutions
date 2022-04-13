class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int j=k-1;
        int l=n-1;
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++)
            lsum+=cardPoints[i];
        if(k==n)
            return lsum; 
        int mx=lsum;
        while(j>=0)
        {
            lsum-=cardPoints[j--];
            rsum+=cardPoints[l--];
            mx=max(mx,lsum+rsum);
        }
        return mx;
    }
};
