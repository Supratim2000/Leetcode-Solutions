class Solution {
public:
    
    void inorder(TreeNode* root,vector<int>& arr)
    {
        if(root==nullptr)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    vector<int> merge(vector<int>& arr1,vector<int>& arr2)
    {
        int i=0;
        int j=0;
        vector<int> ans;
        while(i<arr1.size() && j<arr2.size())
        {
            if(arr1[i]==arr2[j])
            {
                ans.push_back(arr1[i++]);
                ans.push_back(arr2[j++]);
            }
            else if(arr1[i]<arr2[j])
                ans.push_back(arr1[i++]);
            else
                ans.push_back(arr2[j++]);
        }
        if(i==arr1.size())
        {
            while(j<arr2.size())
                ans.push_back(arr2[j++]);
        }
        else
        {
            while(i<arr1.size())
                ans.push_back(arr1[i++]);
        }
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        inorder(root1,list1);
        inorder(root2,list2);
        vector<int> ans=merge(list1,list2);
        return ans;
    }
};
