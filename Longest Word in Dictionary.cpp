class TrieNode {
public:
    char data;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char data) {
        this->data=data;
        for(int i=0;i<26;i++) {
            children.push_back(nullptr);
        }
        isTerminal=false;
    }
};

class Trie {
private:
    void insertHelper(TrieNode* node, string word, int index) {
        if(index==word.size()) {
            node->isTerminal=true;
            return;
        }
        //cout<<"foo"<<endl;
        int childIndex=word[index]-'a';
        if(node->children[childIndex]==nullptr) {
            TrieNode* child=new TrieNode(word[index]);
            node->children[childIndex]=child;
            insertHelper(child,word,index+1);
        } else {
            insertHelper(node->children[childIndex],word,index+1);
        }
    }

    bool searchHelper(TrieNode* node, string word, int index) {
        if(index==word.size()) {
            return node->isTerminal;
        }
        int childIndex=word[index]-'a';
        if(node->children[childIndex]!=nullptr){
            return searchHelper(node->children[childIndex],word,index+1);
        } else {
            return false;
        }
    }

    bool startsWithHelper(TrieNode* node, string prefix, int index) {
        if(index==prefix.size()) {
            return true;
        }
        int childIndex=prefix[index]-'a';
        if(node->children[childIndex]!=nullptr){
            return startsWithHelper(node->children[childIndex],prefix,index+1);
        } else {
            return false;
        }
    }
public:
    TrieNode* root;

    Trie() {
        root=new TrieNode('X');
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

//Implemented using Trie Data Structure
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie=new Trie();
        string ans="";
        for(auto word: words) {
            trie->insert(word);
        }

        for(auto word: words) {
            int count=0;
            TrieNode* node=trie->root;
            for(int i=0;i<word.size();i++) {
                if(word.size()<ans.size())
                    continue;
                char curChar=word[i];
                if(node->children[curChar-'a']->isTerminal)
                    count++;
                node=node->children[curChar-'a'];
            }
            if(count==word.size() && word.size()>=ans.size() && (word.size()>ans.size() || word<ans)) {
                ans=word;
            }
        }

        return ans;
    }
};

//Implemented using unordered_set
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> pres;
        string ans="";
        for(string word: words) {
            pres.insert(word);
        }
        for(auto word:words) {
            bool allPrefixPresent=true;
            string temp="";
            for(int i=0;i<word.size();i++) {
                temp.push_back(word[i]);
                if(pres.find(temp)==pres.end()) {
                    allPrefixPresent=false;
                    break;
                }
            }
            if(allPrefixPresent && (ans=="" || (word.size()==ans.size() && ans>word) || word.size()>ans.size()))
                ans=word;
        }
        return ans;
    }
};
