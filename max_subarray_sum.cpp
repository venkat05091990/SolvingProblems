#include <bits/stdc++.h>

using namespace std;

// brute force O(N^3)
int max_subarray_sum_bf(vector<int> arr){
    int n = arr.size();
    int max_subarray_sum_till_now = INT_MIN;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            if(sum>max_subarray_sum_till_now){
                max_subarray_sum_till_now = sum;
            }
        }
    }
    return max_subarray_sum_till_now;
}

// prefix sum O(N^2)
int max_subarray_sum_prefix_sum(vector<int> arr){
    int n = arr.size();
    vector<int> p(n, 0);
    int max_subarray_sum_till_now = INT_MIN;
    int flag = 0;
    
    // prefix sum array
    p[0] = arr[0];
    for(int i=1; i<n; i++){
        p[i] = p[i-1]+arr[i];
        
        if(arr[i]>0){
            flag = 1;
        }
    }
    
    //all negative
    if(flag==0){
        return 0;
    }
    
    max_subarray_sum_till_now = *max_element(arr.begin(), arr.end());
    
    // main logic
    for(int i=1; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum = 0;
            sum = p[j] - p[i-1];
            if(sum>max_subarray_sum_till_now){
                max_subarray_sum_till_now = sum;
            }
        }
    }
    
    return max_subarray_sum_till_now;
}

// Current Sum Negative Ignore logic O(N)
int max_subarray_sum(vector<int> arr){
    int n = arr.size();
    int max_subarray_sum_till_now = 0;
    
    int curr_sum = 0;
    for(int i=0; i<n; i++)
    {
        if(curr_sum<0){
            curr_sum = 0;
        }
        
        int curr = arr[i];       
        curr_sum += curr;
        if(curr_sum>0 && curr_sum>max_subarray_sum_till_now)
        {
            max_subarray_sum_till_now = curr_sum;
        }
        cout<<max_subarray_sum_till_now<<",";
    }
    return max_subarray_sum_till_now;
}

int main()
{
    vector<int> v = {-1, 2, 3, 4, -2, 6, -8, 3};

    //cout<<max_subarray_sum_bf(v)<<endl;
    //cout<<max_subarray_sum_prefix_sum(v)<<endl;
    cout<<max_subarray_sum(v)<<endl;
    return 0;
}
