class Solution {
public:
    void dfs(Node* root)
    {
        Node* prev=nullptr;
        Node* cur=root;
        Node* nextLevelHead=nullptr;
        
        while(cur)
        {
            while(cur)
            {
                if(cur->left)
                {
                    if(!prev)
                    {
                        prev=cur->left;
                        nextLevelHead=prev;
                    }
                    else
                    {
                        prev->next=cur->left;
                        prev=prev->next; 
                    }
                }
                
                if(cur->right)
                {
                    if(!prev)
                    {
                        prev=cur->right;
                        nextLevelHead=prev;
                    }
                    else
                    {
                        prev->next=cur->right;
                        prev=prev->next;
                    }
                }
                cur=cur->next;
            }
            cur=nextLevelHead;
            prev=nullptr;
            nextLevelHead=nullptr;
        }
    }
    
    Node* connect(Node* root) {
        if(root==nullptr)
            return nullptr;
        Node* obviousRoot=root;
        dfs(root);
        return obviousRoot;
    }
};
