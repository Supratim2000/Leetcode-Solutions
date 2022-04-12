//Using Heap style concept
class CBTInserter {
public:
    vector<TreeNode*> nodeList;
    TreeNode* root=nullptr;
    CBTInserter(TreeNode* root) {
        this->root=root;
        levelOrder(root);
    }
    
    int insert(int val) {
        TreeNode* insNode=new TreeNode(val);
        int n=nodeList.size();
        cout<<n<<endl;
        nodeList.push_back(insNode);
        TreeNode* parent=nodeList[(n-1)/2];
        if(n&1)
            parent->left=insNode;
        else
            parent->right=insNode;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
    
    void levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curNode=q.front();
            q.pop();
            nodeList.push_back(curNode);
            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }
    }
};


//Using Queue
class CBTInserter {
public:
    queue<TreeNode*> adjNodes;
    TreeNode* root=nullptr;
    CBTInserter(TreeNode* root) {
        this->root=root;
        levelOrder(root);
    }
    
    int insert(int val) {
        TreeNode* insNode=new TreeNode(val);
        TreeNode* parent=adjNodes.front();
        if(parent->left==nullptr)
        {
            parent->left=insNode;
            adjNodes.push(insNode);
        }
        else if(parent->right==nullptr)
        {
            parent->right=insNode;
            adjNodes.push(insNode);
            adjNodes.pop();
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
    
    void levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curNode=q.front();
            q.pop();
            if(curNode->left==nullptr || curNode->right==nullptr)
                adjNodes.push(curNode);
            if(curNode->left)
                q.push(curNode->left);
            if(curNode->right)
                q.push(curNode->right);
        }
    }
};
