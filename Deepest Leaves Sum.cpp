class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int count=0;
        if(root==nullptr)
            return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty())
        {
            int n=pendingNodes.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curNode=pendingNodes.front();
                pendingNodes.pop();
                sum+=curNode->val;
                if(curNode->left!=nullptr)
                {
                    pendingNodes.push(curNode->left);
                    count++;
                }
                if(curNode->right!=nullptr)
                {
                    pendingNodes.push(curNode->right);
                    count++;
                }
            }
            if(count==0)
                break;
            count=0;
            sum=0;

        }
        return sum;        
    }
};
