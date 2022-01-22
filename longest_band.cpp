// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int longestband(vector<int> nums){
    unordered_set<int> s;
    int longest_band=1;
    
    //unordered_set
    for(int i : nums){
        s.insert(i);
    }
    
    //checking if the element is start of a band
    for(int i=0; i<nums.size(); i++){
        
        if(s.find(nums[i]-1)==s.end())
        {
            int current = nums[i];
            int count = 1;
            while(s.find(current+1)!=s.end()){
                count++;
                current++;
            }
            if(count > longest_band){
                longest_band = count;
            }
        }
    }
    return longest_band;
}

int main()
{
    vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
    int result = longestband(v);
    cout<<result;
}
