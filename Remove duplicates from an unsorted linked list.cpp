class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head) 
    {
        if(head==nullptr)
            return nullptr;
        unordered_set<int> pres;
        Node* nxt=head;
        Node* prv=new Node(INT_MIN);
        prv->next=head;
        pres.insert(INT_MIN);
        while(nxt)
        {
            if(pres.find(nxt->data)==pres.end())
            {
                pres.insert(nxt->data);
                prv->next=nxt;
                prv=nxt;
            }
            nxt=nxt->next;
        }
        prv->next=nullptr;
        return head;
    }
};
