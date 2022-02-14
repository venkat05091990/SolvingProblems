#include<iostream>
#include<string>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    string s0 = to_string(minutes/60) +":";
    string s1 = to_string(minutes%60);
    if(s1.length()==1){
        s1 = "0"+s1;
    }
    return s0+s1;
}

int main(){
    int min;
    cin>>min;
    cout<<convert_to_digital_time(min);
}
