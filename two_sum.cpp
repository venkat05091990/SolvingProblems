#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& nums, int target) {
      int front = 0, back = nums.size()-1;

      sort(nums.begin(),nums.end());

      while(front < back){
          if(nums[front]+nums[back] == target){
              return true;
          }
          if(nums[front]+nums[back] < target){
              front++;
          }
          else if(nums[front]+nums[back] > target){
              back--;
          }
      }
      return false;
}

int main(){
  vector<int> v = {2, 3, 4, 6};
  int target = 9;
  cout<<twoSum(v, target);
  return 0;
}
