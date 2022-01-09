#include <iostream>

using namespace std;

const int ALPHABET_SIZE =26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};


struct TrieNode *getNode(void){
    struct TrieNode * pNode = new TrieNode();
    pNode->isEndOfWord = false;
    
    
    for(int i=0;i<ALPHABET_SIZE;i++){
        pNode->children[i] = NULL;
    };
    return pNode;
};

void insertTrieNode(string key,struct TrieNode *root){
    struct TrieNode *currentNode = root;
    
    for(int i = 0;i <key.length();i++){
        int index = key[i] - 'a';
        if (!currentNode->children[index]){
            currentNode->children[index] = getNode();
        };
        
        currentNode = currentNode->children[index];
    };
    
    currentNode->isEndOfWord = true;
    cout<<"inserted "<<key<<endl;
};


bool search(string key, struct TrieNode * root){
    struct TrieNode *currentNode = root;
    
    for(int i=0;i <key.length();i++){
        int index = key[i] - 'a';
        
        if(!currentNode->children[index]){
            return false;
        }
        else{
            currentNode = currentNode->children[index];
        }
    }
    return (currentNode->isEndOfWord);
};

int main()
{
    struct TrieNode* root = getNode();
    
    insertTrieNode("abcd",root);
    insertTrieNode("appleby",root);
    insertTrieNode("sachin",root);
    insertTrieNode("ram",root);
    cout<<search("appleby", root)<<endl;
    return 0;
}
