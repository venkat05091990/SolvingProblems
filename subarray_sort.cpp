#include <bits/stdc++.h>

using namespace std;


bool outoforder(vector<int> ip, int key){
    int v = ip[key];
    if(key == 0)
    {
        return v>ip[key+1];
    }
    if(key == ip.size()-1)
    {
        return v<ip[key-1];
    }
    return v < ip[key-1] or v > ip[key+1];
}

pair<int, int> subarray_sort(vector<int> v){
    
    //logic
    int smallest=INT_MAX;
    int largest=INT_MIN;
    
    for(int i=0; i<v.size(); i++)
    {
        if(outoforder(v, i)){
            smallest = min(v[i], smallest);
            largest = max(v[i], largest);
        }
    }
    
    if(smallest==INT_MAX){
        return {-1,-1};
    }
    
    int left = 0;
    while(smallest >= v[left]){
        left++;
    }
    
    int right=v.size()-1;
    while(largest <= v[right]){
        right--;
    }
    
    return {left, right};
}

int main()
{
    vector<int> v = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int, int> result = subarray_sort(v);
    cout<<result.first<<","<<result.second;
    
    return 0;
}
