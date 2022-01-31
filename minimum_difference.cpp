#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//brute force O(M*N)
pair<int,int> minDifference_bf(vector<int> a,vector<int> b){
    //Complete this method
    int minDiff = INT_MAX;
    
    pair<int,int> min_pair;
      for(int i=0; i<a.size(); i++){
          for(int j=0; j<b.size(); j++){
              if(abs(a[i]-b[j]) < minDiff){
                  minDiff = abs(a[i]-b[j]);
                  min_pair = {a[i],b[j]};
              }
          }
      }
    return min_pair;
}

//better algorithm
pair<int, int> minDifference(vector<int> a,vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    pair<int, int> min_pair;
    int min_diff = INT_MAX;
    
    for(int i=0; i<a.size(); i++){
        int curr = a[i];
        
        int b_id = 0;
        while(curr>b[b_id]){
            b_id++;
        }
        
        //value in a less than first element in b
        if(b_id==0){
            int diff = abs(curr - b[0]);
            if(diff<min_diff){
                min_diff = diff;
                min_pair.first = curr;
                min_pair.second = b[0];
            }
            continue;
        }
        
        //value in a greater than last element in b
        if(b_id == b.size()-1){
            int diff = abs(curr - b[b.size()-1]);
            if(diff<min_diff){
                min_diff = diff;
                min_pair.first = curr;
                min_pair.second = b[b.size()-1];
            }  
            continue;
        }
        
        int diff_left = abs(curr-b[b_id-1]);
        int diff_right = abs(b[b_id] - curr);

        if(diff_left < diff_right && diff_left<min_diff){
            min_diff = diff_left;
            min_pair.first = curr;
            min_pair.second = b[b_id-1];
        }
        else if(diff_right < diff_left && diff_right < min_diff){
            min_diff = diff_right;
            min_pair.first = curr;
            min_pair.second = b[b_id];
        }
    }

    return min_pair;
}

int main()
{
    vector<int> a = {23, 5, 10, 17, 30}; // 5 10 17 23 30
    vector<int> b = {26, 134, 135, 14, 19}; // 14 19 26 134 135
    
    pair<int, int> p = minDifference(a, b);
    
    cout<<p.first<<","<<p.second;
    return 0;
}
