#include<iostream>
#include<list>

using namespace std;
 
class Graph{
 
	int V;
	list<pair<int,int> > *l;
 
public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}
 
	void addEdge(int u,int v,int wt,bool undir = true){
 
		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}
	
	void printadjacencylist()
	{
	    for(int i=0;i<V;i++)
	    {
	        cout<<"Vertex : "<<i;
	        for(auto nbr: l[i])
	        {
	            cout<<"-->"<<nbr.first<<"-"<<nbr.second;
	        }
	        cout<<endl;
	    }
	}
 
};
 
int main(){
 
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
	
	g.printadjacencylist();
}
