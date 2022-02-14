/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

string extractStringAtKey(string str, int key){
    char *s = strtok((char *)str.c_str(), " ");
    while(key>1){
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s){
    int ans = 0;
    int p=1;
            
    for(int i=s.length()-1; i>=0; i--){
        ans = ans + (s[i]-'0')*p;
        p=p*10;
    }
    return ans;
}


bool numericCompare(pair<string, string> a, pair<string, string> b){
    string k1 = a.second;
    string k2 = b.second;
    return convertToInt(k1)<convertToInt(k2);
}

bool lexicographicCompare(pair<string, string> a, pair<string, string> b){
    string k1 = a.second;
    string k2 = b.second;
    return k1<k2;   
}

int main()
{
    int n;
    cin>>n;
    
    cin.get(); //consume the extra \n

    string temp;
    vector<string> v;
    
    for(int i=0; i<n; i++){
        getline(cin, temp);
        v.push_back(temp);
    }
    
    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;
    cout<<endl;
    // extract keys
    vector<pair<string, string>> vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i], extractStringAtKey(v[i], key)});
    }
    
    //sort
    if(ordering=="numeric")
    {
        sort(vp.begin(), vp.end(), numericCompare);
    }
    
    if(ordering=="lexicographic")
    {
        sort(vp.begin(), vp.end(), lexicographicCompare);
    }
    
    //reverse
    if(reversal=="reverse")
    {
        reverse(vp.begin(), vp.end());
    }
    
    //output
    for(int i=0; i<n; i++){
        cout<<vp[i].first<<endl;
    }
}
