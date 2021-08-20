class Solution {
public:    
    int countBits(int n) {return (int)log2(n)+1;}
    
    int powerOfTwo(int n) {return 1<<n;}
    
    int getParent(int n,int max,int min)
    {
        int diff=n-max; 
        int distFromParent=(diff-1)/2;
        int parent=max-distFromParent;
        return parent;
    }
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int numLevel=countBits(label);
        ans.push_back(label);
        while(numLevel!=1)
        {
            int min=powerOfTwo(numLevel-2);
            int max=powerOfTwo(numLevel-1)-1;
            label=getParent(label,max,min);
            ans.push_back(label);
            numLevel--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
