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

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
