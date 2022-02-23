#include <iostream>
#include <list>
#include <queue>
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
    
    //bfs
    
    void bfs(int source)
    {
        //queue of integers
        queue<int> q;
        
        //visited array to avoid the cycles
        vector<bool> visited(V, false);
        
        //push the source
        q.push(source);
        visited[source]=true;
        
        while(!q.empty())
        {
            int temp = q.front();
            
            cout<<temp;
            q.pop();
            
            for(auto nbr:l[temp])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
            
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
    g.addEdge(5,6);
    
    g.printAdjList();
    
    cout<<"-------------"<<endl;
    
    g.bfs(1);
    return 0;
}
