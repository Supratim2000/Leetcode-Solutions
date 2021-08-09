class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool oddValLvl=true;
        bool f_time=true;
        int prev;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=q.front();
                q.pop();
                if(oddValLvl)
                {
                    if(curNode->val%2==0)
                        return false;
                    if(f_time)
                        f_time=false;
                    else if(curNode->val<=prev)
                            return false; 
                    prev=curNode->val;
                }
                else
                {
                    if(curNode->val%2!=0)
                        return false;
                    if(f_time)
                        f_time=false;
                    else if(curNode->val>=prev)
                            return false;
                    prev=curNode->val;
                }
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
            f_time=true;
            oddValLvl=!oddValLvl;
        }
        return true;
    }
};
