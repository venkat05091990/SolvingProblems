#include<bits/stdc++.h>
using namespace std;

void replacestring(char* ip){
    // spaces
    int spaces = 0;
    for(int i=0; ip[i]!='\0'; i++){
        if(ip[i]==' ')
            spaces++;
        }
    
    // last index "\0"
    int last_id = strlen(ip) + spaces*2;
    ip[last_id]='\0';
    
    
    //O(N)
    for(int i=strlen(ip)-1; i>=0; i--){
        if(ip[i]==' '){
            ip[last_id-1]='0';
            ip[last_id-2]='2';
            ip[last_id-3]='%';
            last_id = last_id-3;
        }
        else{
            ip[last_id-1]=ip[i];
            last_id--;
        }
    }
}


int main()
{
    char ip[200];
    cin.getline(ip,100);
    replacestring(ip);
    cout<<ip;
    return 0;
}
