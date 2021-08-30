//Using linked list
class MyHashMap {
public:
    class Node
    {
        public:
            pair<int,int> val;
            Node* next;
            Node(int key,int value)
            {
                val.first=key;
                val.second=value;
                next=nullptr;
            }
    };
    
    Node* head;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        head=nullptr;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        Node* t=head;
        while(t)
        {
            if(t->val.first==key)
            {
                t->val.second=value;
                return;
            }
            t=t->next;
        }
        Node* temp=new Node(key,value);
        temp->next=head;
        head=temp;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Node* t=head;
        while(t)
        {
            if(t->val.first==key)
                return t->val.second;
            t=t->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Node* p=nullptr;
        Node* t=head;
        while(t)
        {
            if(t->val.first==key)
            {
                Node* toDelete=t;
                if(!p)
                {
                    head=head->next;
                    t=head;
                }
                else
                {
                    p->next=t->next;
                    t=t->next;
                }
                delete toDelete;
                return;
            }
            p=t;
            t=t->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
