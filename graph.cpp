#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
	string node_value;
public:
	Node(string ip){
		this->node_value = ip;
	}
};

class Graph{
	int V;
	vector<Node*> nodes;
	unordered_map<string, string> edges;
public:
	void add_node(string ip){
		Node* tmp = new Node(ip);
		nodes.push_back(tmp);
	}	

	void add_edge(string start_edge, string end_edge, bool undirected =true){
		edges[start_edge] = end_edge;
		if(undirected){
			edges[end_edge] = start_edge;
		}
	}
	
	bool is_edge_present(string v1, string v2, bool undirected =true){
	    if(undirected){
	        if((edges[v1] == v2) and (edges[v2] == v1)){
	            return true;
	        }
	    }
	    else{
	        if(edges[v1] == v2){
	            return true;
	        }	        
	    }
        return false;
	}
};

int main()
{
    Graph *g = new Graph();
    g->add_node("ram");
    g->add_node("shyam");    
    g->add_node("sachin");
    g->add_node("rajesh");
    g->add_edge("ram","shyam");
    g->add_edge("sachin","rajesh");  
    cout<<g->is_edge_present("ram","shyam")<<endl;
    cout<<g->is_edge_present("ram","sachin")<<endl;
    cout<<g->is_edge_present("sachin","rajesh")<<endl;

    return 0;
}
