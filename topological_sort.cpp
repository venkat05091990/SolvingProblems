#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    //pointer to list of integer type
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEgde(int x, int y)
    {
        l[x].push_back(y);
    }
    
    void topological_sort()
    {
        //indegree vector
        vector<int> indegree(V,0);
        
        //iterate over all edges to find the right indegree
        for(int i=0;i<V;i++)
        {
            for(auto nbr: l[i])
            {
                indegree[nbr]++;
            }
        }
        
        //bfs
        queue<int> q; 
        
        //initialize with nodes with 0 indegree
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        
        //start popping
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<< " ";
            q.pop();
            
            //iterate over the nodes of this node and reduce their indegree by char16_t
            for(auto nbr : l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }
}


