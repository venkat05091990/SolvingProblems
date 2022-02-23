#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    //total vertices
    int V;
    //adjacency list
    list<int> *l;

public:
    //initialize
    Graph(int V)
    {
        this->V=V;
        this->l = new list<int>[V];
    }
    
    //add edge 
    void addEdge(int u, int v, bool undir=true)
    {
        l[u].push_back(v);
        if(undir)
        {
            l[v].push_back(u);
        }
    }
    
    //display adjacency list
    void printAdjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex : "<<i;
            
            for(auto j: l[i])
            {
                cout<<"-->"<<j;
            }
            cout<<endl;
        }
    }
    
    
    
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,4);    
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    
    g.printAdjList();
    return 0;
}
