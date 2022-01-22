// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int mountain(vector<int> nums){
    
    vector<int> peaks;
    int n = nums.size();
    int max_mountain=0;
    
    //peaks
    for(int i=1;i<n-1;i++){
        if(nums[i]>nums[i-1] && nums[i+1]<nums[i]){
            peaks.push_back(i);
        }
    }
    
    //mountian size
    for(int i=0;i<peaks.size();i++){
        int current_peak = peaks[i];
        int leftptr = current_peak;
        int rightptr = current_peak;
        
        while(leftptr>0 && nums[leftptr]>nums[leftptr-1]){
            leftptr--;
        }
        
        while(rightptr<n-1 && nums[rightptr]>nums[rightptr+1]){
            rightptr++;
        }
        
        int width = rightptr - leftptr + 1;

        if(width > max_mountain){
            max_mountain = width;
        }
    }

    return max_mountain;
}

int main(){
    vector<int> v = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int result = mountain(v);
    cout<<result;
}
