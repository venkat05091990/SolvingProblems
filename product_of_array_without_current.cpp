#include<bits/stdc++.h>

using namespace std;

//O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //Two product arrays O(2N)
    vector<int> p_left(n,1);
    vector<int> p_right(n,1);
    
    //two pointers
    int i=0;
    int j=n-1;
    int left_prod=1;
    int right_prod=1;
    
    //two prod arrays O(N)
    while(i<=n-1 and j>=0){
        left_prod = left_prod*arr[i];
        right_prod = right_prod*arr[j];
        p_left[i]=left_prod;
        p_right[j]= right_prod;
        i++;
        j--;
    }
    
    output[0]=p_right[1];
    output[n-1]=p_left[n-2];
    
    //update the output array and return O(N)
    for(int i=1; i<n-1; i++){
        output[i]=p_left[i-1]*p_right[i+1];
    }
    return output;
}

int main()
{
    vector<int> a = {2, 3, 4, 5, 6};
    
    vector<int> b = productArray(a);
    
    for(int v : b){
        cout<<v<<" ";
    }
    return 0;
}
