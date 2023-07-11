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

//Using Trie
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie=new Trie();
        string ans="";
        for(auto element: strs)
            trie->insert(element);
        
        if(trie->root->isTerminal)
            return "";

        int notNullInRootCount=0;
        for(int i=0;i<trie->root->children.size();i++)
        {
            if(trie->root->children[i]!=nullptr)
                notNullInRootCount++;
        }

        if(notNullInRootCount>1)
            return "";
        else
        {
            TrieNode* node=trie->root;
            string word=strs[0];
            while(node)
            {
                ans.push_back(node->data);
                int count=0;
                int index=0;
                for(int i=0;i<node->children.size();i++)
                {
                    if(node->children[i]!=nullptr)
                    {
                        index=i;
                        count++;
                    }
                }
                if(count!=1 || node->isTerminal==true)
                    break;
                node=node->children[index];
            }

            return ans.substr(1);       
        }
    }
};

//Without using extra space
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int point=0;
        string ans="";
        int smallestStringSize=INT_MAX;
        for(auto word: strs)
        {
            if(word.size()<smallestStringSize)
                smallestStringSize=word.size();
        }
        
        while(point<smallestStringSize)
        {
            for(int i=0;i<n;i++)
            {
                if(strs[i][point]!=strs[0][point])
                    return ans;
            }
            ans.push_back(strs[0][point]);
            point++;
        }
        return ans;
    }
};
