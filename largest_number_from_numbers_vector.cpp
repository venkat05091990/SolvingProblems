#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    string a_s = to_string(a);
    string b_s = to_string(b);
    return a_s+b_s>b_s+a_s?true:false;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    string s ="";
    sort(numbers.begin(), numbers.end(), compare);
    for(auto n :numbers){
        s+=to_string(n);
    }
    return s;
}

int main(){
    vector<int> n = {10,11,20,30,3};
    cout<<concatenate(n);
}
