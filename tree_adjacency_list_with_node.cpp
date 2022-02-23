#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;


class Node
{
public:
    string name;
    list<string> nbrs;
    
    Node(string name)
    {
        this->name=name;
    }
};

class Graph
{
private:
    // stores addresses of nodes by their names
    unordered_map<string,Node*> m;

public:
    Graph(vector<string> cities)
    {
        for(string city:cities)
        {
           m[city] = new Node(city);
        }
    }
    
    void addEdge(string x, string y, bool undir=true)
    {
        m[x]->nbrs.push_back(y);
        if(undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }
    
    void printadjacencylist()
    {
        for(auto cityPair : m)
        {
            string city = cityPair.first;
            cout<<"City : "<<city;
            Node* city_o = cityPair.second;
            list<string> ns = city_o->nbrs;
            
            for(string n: ns)
            {
                cout<<"-->"<<n;
            }
            cout<<endl;
        }
    }
};


int main()
{
    vector<string> cities = {"New Delhi", "Mumbai","Kolkata","Chennai","Hyderabad","Bengaluru"};
    Graph g(cities);
    
    g.addEdge("New Delhi","Mumbai");
    g.addEdge("New Delhi","Hyderabad");
    g.addEdge("New Delhi","Kolkata");
    g.addEdge("New Delhi","Chennai");
    g.addEdge("Chennai","Hyderabad");
    g.addEdge("Hyderabad","Kolkata");
    
    g.printadjacencylist();

    return 0;
}
