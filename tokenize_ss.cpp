#include<bits/stdc++.h>
using namespace std;

vector<string> tokenize(string ip){
    stringstream ss(ip);
    
    string token;
    vector<string> tokens;
    while(getline(ss, token, ' ')){
        tokens.push_back(token);
    }
    return tokens;
}


int main()
{
    string ip;
    getline(cin, ip);
    vector<string> v = tokenize(ip);
    for(auto s:v){
        cout<<s<<",";
    }
    return 0;
}
