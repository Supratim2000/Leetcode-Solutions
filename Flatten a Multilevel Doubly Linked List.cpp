class Solution {
public:
    Node* flatten(Node* head) {
        Node* t=head;
        Node* mainTail;
        stack<Node*> levelNode;
        while(t)
        {
            if(!t->next)
                mainTail=t;
            if(t->child)
            {
                Node* nx=t->next;
                Node* y=nullptr;
                if(!nx)
                {
                    y=t;
                    t=t->child;
                    y->next=t;
                    t->prev=y;
                }
                else
                {
                    levelNode.push(nx);
                    nx->prev=nullptr;
                    t->next=t->child;
                    t->child->prev=t;
                    y=t;
                    t=t->child;
                }
                y->child=nullptr;
            }
            else
                t=t->next;
        }
        Node* prevTail=mainTail;        
        while(!levelNode.empty())
        {
            Node* subHead=levelNode.top();
            levelNode.pop();
            prevTail->next=subHead;
            subHead->prev=prevTail;
            while(prevTail->next)
                prevTail=prevTail->next;
        }   
        return head;
    }
};
