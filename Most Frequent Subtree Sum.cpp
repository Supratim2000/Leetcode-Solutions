class Solution {
public:
    
    int subTreeSum(TreeNode* root,vector<int>& ans,unordered_map<int,int>& freq)
    {
        if(root==0)
            return 0;
        int leftSubTreeSum=0;
        int rightSubTreeSum=0;
        if(root->left)
            leftSubTreeSum=subTreeSum(root->left,ans,freq);
        if(root->right)
            rightSubTreeSum=subTreeSum(root->right,ans,freq);
        int curSubTreeSum=root->val+leftSubTreeSum+rightSubTreeSum;
        freq[curSubTreeSum]++;
        return curSubTreeSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        unordered_map<int,int> freq;
        subTreeSum(root,ans,freq);
        int maxFreq;
        for(auto x: freq)
            maxFreq=max(maxFreq,x.second);
        for(auto x: freq)
            if(x.second==maxFreq)
                ans.push_back(x.first);
        return ans;
    }
};
