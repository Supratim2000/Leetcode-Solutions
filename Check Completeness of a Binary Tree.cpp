class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool isNullEnc=false;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();                
                if(curNode==nullptr)
                    isNullEnc=true;
                else
                {
                    if(isNullEnc)
                        return false;
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
            }
        }
        return isNullEnc;
    }
};
