#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsequences(string s, string o, vector<string> &v){
    
    //base case
    if(s.size()==0){
        v.push_back(o);
        return;
    }
    
    //rec case
    char ch=s[0];
    string reduced_string = s.substr(1);
    
    //includes
    subsequences(reduced_string, o+ch, v);
    
    //excludes
    subsequences(reduced_string, o, v);
}

bool compare(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }
    else return a.length()<b.length();
}

int main()
{
    string s="abc";
    vector<string> v;
    
    // subsequences
    subsequences(s,"",v);
    
    // sort subsequences
    sort(v.begin(), v.end(), compare);
    
    for(auto a :v){
        cout<<a<<",";
    }
}
