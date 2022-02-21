#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &array, int s, int e)
{
    int pivot = array[e];
    int i = s-1;
    
    for(int j=s;j<e;j++)
    {
        if(array[j]<pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1],array[e]);
    return i+1;
}

int quickselect(vector<int> &array, int s, int e, int key)
{
    //rec case
    int p = partition(array,s,e);
    if(p==key)
    {
        return array[p];    
    }
    else if(p<key)
    {
        return quickselect(array,p+1,e, key);
    }
    else
    {
        return quickselect(array,s,p-1, key);
    }
}


int main()
{
    vector<int> ip = {10,5,2,0,7,6,4};
    int key = 4;
    cout<<quickselect(ip, 0, ip.size()-1, key);
    return 0;
}
