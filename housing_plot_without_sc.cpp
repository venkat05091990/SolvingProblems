#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> housing_without_on_space(vector<int> ip, int key){
    // size
    int n = ip.size();
    
    //output
    vector<pair<int, int>> op;
    
    //current_sum cs
    int i=0, j=0;
    int cs=0;
    
    while(j<n){
        
        // expand to right
        cs += ip[j];
        j++;
        
        // remove elements from left
        while(cs > key and i<j){
            cs = cs - ip[i];
            i++;
        }
        
        if(cs==key){
            op.push_back({i,j-1});   
        }
    }

    return op;
}


int main()
{
    vector<int> plots = {1, 2, 3 ,5, 2, 1, 3, 2, 4, 8, 5};
    int key = 6;
    // display indices
    vector<pair<int, int>> op = housing_without_on_space(plots, key);
    
    for(auto p:op){
        cout<<p.first<<"-"<<p.second<<endl;
    }
    return 0;
}
