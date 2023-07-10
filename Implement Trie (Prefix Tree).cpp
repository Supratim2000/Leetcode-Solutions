class TrieNode {
private:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;
public:
    TrieNode(char data) {
        this->data=data;
        for(int i=0;i<26;i++) {
            children.push_back(nullptr);
        }
        isTerminal=false;
    }

    char getData() {
        return this->data;
    }
    
    vector<TrieNode*> getChildren() {
        return this->children;
    }

    bool getIsTerminal() {
        return this->isTerminal;
    }

    void setIsTerminal(bool isTerminal) {
        this->isTerminal=isTerminal;
    }

    void setChildIndex(int index, TrieNode* node) {
        if(index<26 && node) {
            this->children[index]=node;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    void insertHelper(TrieNode* node, string word, int index) {
        if(index==word.size()) {
            node->setIsTerminal(true);
            return;
        }
        int childIndex=word[index]-'a';
        if(node->getChildren()[childIndex]==nullptr) {
            TrieNode* child=new TrieNode(word[index]);
            node->setChildIndex(childIndex,child);
            insertHelper(child,word,index+1);
        } else {
            insertHelper(node->getChildren()[childIndex],word,index+1);
        }
    }

    bool searchHelper(TrieNode* node, string word, int index) {
        if(index==word.size()) {
            return node->getIsTerminal();
        }
        int childIndex=word[index]-'a';
        if(node->getChildren()[childIndex]!=nullptr){
            return searchHelper(node->getChildren()[childIndex],word,index+1);
        } else {
            return false;
        }
    }

    bool startsWithHelper(TrieNode* node, string prefix, int index) {
        if(index==prefix.size()) {
            return true;
        }
        int childIndex=prefix[index]-'a';
        if(node->getChildren()[childIndex]!=nullptr){
            return startsWithHelper(node->getChildren()[childIndex],prefix,index+1);
        } else {
            return false;
        }
    }
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        insertHelper(root,word,0);
    }
    
    bool search(string word) {
        return searchHelper(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
