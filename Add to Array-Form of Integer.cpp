class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> ans;
        int x=k;
        int i=n-1;
        int sum=0,carry=0;
        while(x!=0 && i>=0)
        {
            int n1=x%10;
            int n2=num[i];
            int res=n1+n2+carry;
            sum=res%10;
            carry=res/10;
            ans.push_back(sum);
            x/=10;
            i--;
        }
        if(x==0)
        {
            while(i>=0)
            {
                int res=num[i]+carry;
                sum=res%10;
                carry=res/10;
                ans.push_back(sum);
                i--;
            }
        }
        else
        {
            while(x)
            {
                int res=(x%10)+carry;
                sum=res%10;
                carry=res/10;
                ans.push_back(sum);
                x/=10;    
            }
        }
        
        if(carry!=0)
            ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        
        return ans; 
    }
};
