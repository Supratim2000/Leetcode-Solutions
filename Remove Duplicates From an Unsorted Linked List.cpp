class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head) 
    {
        if(!head)
            return nullptr;
        unordered_set<int> pres;
        Node* cur=head;
        Node* prev=new Node(INT_MIN);
        prev->next=cur;
        pres.insert(INT_MIN);
        while(cur)
        {
            if(pres.find(cur->data)==pres.end())
            {
                pres.insert(cur->data);
                prev->next=cur;
                prev=cur;
            }
            cur=cur->next;
        }
        prev->next=nullptr;
        return head;
    }
};
