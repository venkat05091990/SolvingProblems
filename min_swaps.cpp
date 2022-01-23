#include <bits/stdc++.h>
using namespace std;

int countMinSwaps(vector<int> arr){
    
    int ans = 0;
    int n =arr.size();
    
    //store the current indices
    pair<int, int> ap[n];
    for(int i=0; i<n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    
    //sort
    sort(ap, ap+n);
    
    ///build the main logic
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        int old_position = ap[i].second;
        //if element is visited or element is in right position
        if(visited[i]==true or old_position==i){
            continue;
        }
        //if element is being visited for first time
        int node = i;
        int cycle = 0;
        
        while(!visited[node]){
            visited[node]= true;
            int next_node = ap[node].second;
            node = next_node;
            cycle +=1;
        }
        ans += (cycle-1);
        
    }
    return ans;
    
}


int main()
{
    vector<int> v = {5,4,3,2,1};
    int result = countMinSwaps(v);
    cout<<result;
    return 0;
}
