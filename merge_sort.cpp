#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int s, int m, int e)
{
    int i = s;
    int j = m+1;
    
    vector<int> temp;
    
    while(i<=m and j<=e)
    {
        if(array[i]<array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }
    
    while(i<=m)
    {
        temp.push_back(array[i++]);
    }
    
    while(j<=e)
    {
        temp.push_back(array[j++]);
    }
    
    for(int i=s;i<=e;i++)
    {
        array[i]=temp[i-s];
    }
    return;
}

void mergesort(vector<int> &array, int s, int e)
{
    //base case
    if(s>=e)
    {
        return;    
    }
    
    // mid element
    int m = (s + e)/2;
    
    mergesort(array, s, m);
    mergesort(array, m+1, e);
    
    merge(array, s, m, e);
    return;
}


int main()
{
    vector<int> ip = {2,5,2,1,3,4,8,1,0,5};
    mergesort(ip, 0, ip.size()-1);
    for(auto n:ip)
    {
        cout<<n<<"--";
    }
    return 0;
}
