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
    
    	    //shortest path from any vertex in an undirected graph
    void shortest_path(int source, int dest=-1)
    {
        //queue of integers
        queue<int> q;
        
        //visited array to avoid the cycles
        vector<bool> visited(V, false);
        
        //distance array
        vector<int> d(V,0);
        
        //parent array
        vector<int> p(V,-1);
        
        //push the source
        q.push(source);
        visited[source]=true;
        d[source]=0;
        p[source]=source;
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(auto nbr:l[temp])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    p[nbr]=temp;
                    d[nbr] = d[temp] + 1;
                    q.push(nbr);
                }
            }
            
        }
        
        //print the shortest distance
        for(int i=0;i<V;i++)
        {
            cout<<"shortest distance from "<<source <<" to "<<i<<"is "<<d[i]<<endl;
        }
        
        //print the shortest path from source to dest
        
        if(dest!=-1)
        {
            int temp = dest;
            while(temp!=source)
            {
                cout<<"--"<<temp;
                temp = p[temp];
            }
            cout<<"--"<<source;
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
    
    g.shortest_path(0,5);
    return 0;
}
