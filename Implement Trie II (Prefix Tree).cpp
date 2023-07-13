#include <bits/stdc++.h> 
class TrieNode {
    public:
        char data;
        vector<TrieNode*> children;
        int countPrefix;
        int endsWith;

        TrieNode(char data) {
            this->data=data;
            for(int i=0;i<26;i++) {
                children.push_back(nullptr);
            }
            this->countPrefix=0;
            this->endsWith=0;
        }
};

class Trie{
    private:
        void insertHelper(string st,TrieNode* node,int i) {
            if(i==st.size()) {
                node->endsWith++;
                return;
            }
            char curChar=st[i];
            int curCharIndex=curChar-'a';
            if(node->children[curCharIndex]==nullptr) {
                TrieNode* child=new TrieNode(curChar);
                child->countPrefix=1;
                node->children[curCharIndex]=child;
                insertHelper(st,child,i+1);
            } else {
                node->children[curCharIndex]->countPrefix++;
                insertHelper(st,node->children[curCharIndex],i+1);
            }
        }

        int countWordsHelper(string st,TrieNode* node,int i) {
            if(i==st.size()) {
                return node->endsWith;
            }
            char curChar=st[i];
            int curCharIndex=curChar-'a';
            if(node->children[curCharIndex]==nullptr) {
                return 0;
            } else {
                return countWordsHelper(st,node->children[curCharIndex],i+1);
            }
        }

        int countWordsStartingHelper(string st,TrieNode* node,int i) {
            if(i==st.size()) {
                return node->countPrefix;
            }
            char curChar=st[i];
            int curCharIndex=curChar-'a';
            if(node->children[curCharIndex]==nullptr) {
                return 0;
            } else {
                return countWordsStartingHelper(st,node->children[curCharIndex],i+1);
            }
        }

        void eraseHelper(string st,TrieNode* node,int i) {
            if(i==st.size()) {
                node->endsWith--;
                return;
            }
            char curChar=st[i];
            int curCharIndex=curChar-'a';
            node->children[curCharIndex]->countPrefix--;
            eraseHelper(st,node->children[curCharIndex],i+1);
        }

    public:
        TrieNode* root;

        Trie(){
            root=new TrieNode('X');
        }

        void insert(string &word){
            insertHelper(word,root,0);
        }

        int countWordsEqualTo(string &word){
            return countWordsHelper(word,root,0);
        }

        int countWordsStartingWith(string &word){
            return countWordsStartingHelper(word,root,0);
        }

        void erase(string &word){
            eraseHelper(word,root,0);
        }
};
