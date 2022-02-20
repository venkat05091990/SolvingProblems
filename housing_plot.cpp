#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> housing(vector<int> ip, int key){
    // size
    int n = ip.size();
    
    //output
    vector<pair<int, int>> op;
    
    // prefix sum O(N)
    vector<int> ps(n);
    ps[0]=ip[0];
    for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+ip[i];
    }
    
    // two pointers
    int i=0, j=0;
    
    // O(N)
    while(i<n && j<n){
        int st = i>0?ps[i-1]:0;
        int end = ps[j];
        
        if(end-st==key){
            op.push_back({i,j});
            i++;
        }
        if(end-st>key){
            i++;
        }
        if(end-st<key){
            j++;
        }
    }
    return op;
}


int main()
{
    vector<int> plots = {1, 2, 3 ,5, 2, 1, 3, 2, 4, 8, 5};
    int key = 6;
    // display indices
    vector<pair<int, int>> op = housing(plots, key);
    
    for(auto p:op){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
