//Using Array
class MyHashSet {
public:
    
    bool* hash;
    
    /** Initialize your data structure here. */
    MyHashSet() {
        hash=new bool[1000001];
        for(int i=0;i<1000001;i++)
            hash[i]=false;
    }
    
    void add(int key) {
        hash[key]=true;
    }
    
    void remove(int key) {
        hash[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

//Using Singly linked list
class MyHashSet {
public:
    
    class Node
    {
        public:
            int val;
            Node* next;
            Node(int val)
            {
                this->val=val;
                next=nullptr;
            }
    };
    
    Node* head;
    
    MyHashSet() {
        head=nullptr;
    }
    
    void add(int key) {
        if(!contains(key))
        {
            if(head==nullptr)
                head=new Node(key);
            else
            {
                Node* temp=new Node(key);
                temp->next=head;
                head=temp;
            }
        }
    }
    
    void remove(int key) {
        Node* p=nullptr;
        Node* t=head;
        while(t)
        {
            if(t->val==key)
            {
                if(p==nullptr)
                {
                    head=head->next;
                    Node* toDelete=t;
                    t=head;
                    delete toDelete;
                }
                else
                    p->next=t->next;
                return;
            }
            p=t;
            t=t->next;
        }
    }
    
    bool contains(int key) {
        Node* t=head;
        while(t)
        {
            if(t->val==key)
                return true;
            t=t->next;
        }
        return false;
    }
};
