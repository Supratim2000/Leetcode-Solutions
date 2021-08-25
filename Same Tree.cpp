//Method 1(DFS)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && p->val==q->val;
    }
};

//Method 2(BFS)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>> qu;
        qu.push({p,q});
        while(!qu.empty())
        {
            int n=qu.size();
            for(int i=0;i<n;i++)
            {
                pair<TreeNode*,TreeNode*> curNodes=qu.front();
                qu.pop();
                if(!curNodes.first && !curNodes.second)
                    continue;
                else if(!curNodes.first || !curNodes.second)
                    return false;
                else if(curNodes.first->val!=curNodes.second->val)
                        return false;
                qu.push({curNodes.first->left,curNodes.second->left});
                qu.push({curNodes.first->right,curNodes.second->right});
            }
        }
        return true;
    }
};
