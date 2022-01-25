#include<unordered_map>
#include<unordered_set>
#include<queue>

bool isLeaf(BinaryTreeNode<int>* root)
{
    return !root->left && !root->right;
}

bool visited(unordered_set<BinaryTreeNode<int>*>& vis, BinaryTreeNode<int>* node)
{
    return vis.find(node)!=vis.end();
}

void genParents(BinaryTreeNode<int>* root, BinaryTreeNode<int>* par, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent, int target, BinaryTreeNode<int>*& tRef)
{
    if(!root)
        return;
    if(root->data==target)
        tRef=root;
    parent.insert({root, par});
    genParents(root->left, root, parent, target, tRef);
    genParents(root->right, root, parent, target, tRef);
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    if(!root || isLeaf(root))
        return 0;
    else
    {
        int level=-1;
        BinaryTreeNode<int>* tRef=nullptr;
        unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
        unordered_set<BinaryTreeNode<int>*> vis;
        genParents(root, nullptr, parent,start ,tRef);
        vis.insert(tRef);
        queue<BinaryTreeNode<int>*> qu;
        qu.push(tRef);
        
        while(!qu.empty())
        {
            int n=qu.size();
            for(int i=0;i<n;i++)
            {
                BinaryTreeNode<int>* curNode=qu.front();
                qu.pop();
                if(parent[curNode] && !visited(vis, parent[curNode]))
                {
                    vis.insert(parent[curNode]);
                    qu.push(parent[curNode]);
                }
                if(curNode->left && !visited(vis, curNode->left))
                {
                    vis.insert(curNode->left);
                    qu.push(curNode->left);
                }
                if(curNode->right && !visited(vis, curNode->right))
                {
                    vis.insert(curNode->right);
                    qu.push(curNode->right);
                }
            }
            level++;
        }
        return level;
    }
}
