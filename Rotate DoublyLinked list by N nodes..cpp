#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;

class Node
{
    public:
        ll val;
        Node* next;
        Node* prev;
        Node(ll val)
        {
            this->val=val;
            this->next=nullptr;
            this->prev=nullptr;
        }
};

void insert(Node** head, ll data)
{
    Node* temp=new Node(data);
    if(*head==nullptr)
        *head=temp;
    else
    {
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
    }
}

void show(Node* head)
{
    Node* h=head;
    while(h)
    {
        cout<<h->val<<"->";
        h=h->next;
    }
    cout<<"NULL"<<endl;
}

Node* rotateByN(Node* head,ll n)
{
    Node* newHead=nullptr;
    Node* cur=head;
    Node* prv=nullptr;
    for(ll i=0;i<n;i++)
    {
        prv=cur;
        cur=cur->next;
    }
    if(!cur || !prv)
        return head;
    prv->next=nullptr;
    cur->prev=nullptr;
    newHead=cur;
    while(cur->next)
        cur=cur->next;
    cur->next=head;
    head->prev=cur;
    return newHead;
}

int main()
{
    Node* head=nullptr;
    ll n=2;
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    show(head);
    Node* modifiedHead=rotateByN(head,n);
    cout<<"After rotation by "<<n<<": ";
    show(modifiedHead);

    return 0;
}
