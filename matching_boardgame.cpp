#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define M 3
#define N 4

// create a trie node
class Node
{
public:
    char data;
    unordered_map<char, Node*> children;
    string word;
    bool isTerminal;
    
    
    Node(char data)
    {
        this->data=data;
        isTerminal = false;
        word="";
    }
};

//create a trie
class Trie
{
public:
    Node* root;
    
    Trie()
    {
        root = new Node('\0');
    }
    
    //add the word to Trie
    void addWord(string word)
    {
        
        Node* temp = root;
        for(auto ch:word)
        {
            if(temp->children.count(ch)==0)
            {
                temp->children[ch]= new Node(ch);
            }
            temp = temp->children[ch];
        }
        
        temp->isTerminal = true;
        temp->word = word;
    }

};


void dfs(char board[M][N], Node* node, int i, int j, bool visited[][N], unordered_set<string> &output)
{
    // base case
    char ch = board[i][j];
    if(node->children.count(ch) == 0)
    {
        return;
    }
    
    //otherwise
    visited[i][j]=true;
    node = node->children[ch];
    
    //if it is a terminal node in the Trie
    if(node->isTerminal)
    {
        output.insert(node->word);
    }
    
    
    //do 8 way dfs
    
    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};
    
    for(int k=0;k<8;k++)
    {
        int ni = i+dx[k];
        int nj = j+dy[k];
        
        if(ni>=0 and nj>=0 and ni<=M and nj<N and !visited[ni][nj])
        {
            dfs(board,node,ni,nj,visited,output);
        }
    }
    
    // last step 
    visited[i][j] = false;
    return;
}


int main()
{
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO" ,"TUNES", "CAT"};

    char board[M][N] = {
        {'S','E','R','T'},
        {'U','N','K','S'},
        {'T','C','A','T'},
    };
    
    Trie t;
    
    //develop the trie
    for(auto word :words)
    {
        t.addWord(word);
    }
    
    //visited
    bool visited[M][N] = {0};
    
    //output to avoid the duplicates
    unordered_set<string> output;
    
    //8 way dfs search from every cell
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            dfs(board, t.root, i, j, visited, output);
            //reset the visited array after every cell
        }
    }
    
    // display the output
    for(auto o: output)
    {
        cout<<o<<endl;
    }
    return 0;
}
