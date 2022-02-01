#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int n = big.size();
    int m = small.size();
    int id = 0;
    //get first occurrences
    while(id!=-1 && id<=n-m){
        id = big.find(small,id);
        if(id!=-1){
            result.push_back(id);
            id = id + m;
        }
    }
    return result;
}

int main()
{
    string bigstring = "i like the movie. the movie has very good actors. movie is a blockbuster";
    string smallstring = "movie";
    vector<int> p = stringSearch(bigstring, smallstring);
    for(int n : p){
        cout<<n<<",";
    }
    return 0;
}
