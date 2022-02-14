#include <iostream>

using namespace std;

bool isSubset(string s1, string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    
    while(i>=0 and j>=0){
        if(s1[i]==s2[j]){
            i--;
            j--;
        }
        else{
            i--;
        }
    }
    
    if(j==-1){
        return true;
    }
    return false;
}

int main()
{
    string s1,s2;
    s1 ="apple";
    s2 ="app";
    cout<<isSubset(s1, s2);
}
