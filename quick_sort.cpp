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

void quicksort(vector<int> &array, int s, int e)
{
    //base case
    if(s>=e)
    {
        return;
    }
    
    //rec case
    int p = partition(array,s,e);
    quicksort(array,s,p-1);
    quicksort(array,p+1,e);

}

int main()
{
    vector<int> ip = {10,5,2,0,7,6};
    quicksort(ip, 0, ip.size()-1);
    for(auto n:ip)
    {
        cout<<n<<"--";
    }
    return 0;
}
