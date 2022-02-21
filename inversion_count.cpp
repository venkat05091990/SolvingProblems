#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &array, int s, int m, int e)
{
    int i = s;
    int j = m+1;
    int count = 0;
    
    vector<int> temp;
    
    while(i<=m and j<=e)
    {
        if(array[i]<array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else if(array[i]>array[j])
        {   //inversion count
        
            count = count + (m - i + 1);
            temp.push_back(array[j]);
            j++;
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
    return count;
}

int inversioncount(vector<int> &array, int s, int e)
{
    //base case
    if(s>=e)
    {
        return 0;    
    }
    
    // mid element
    int m = (s + e)/2;
    
    int c1 = inversioncount(array, s, m);
    int c2 = inversioncount(array, m+1, e);
    
    int c3 = merge(array, s, m, e);
    
    return c1+c2+c3;
}


int main()
{
    vector<int> ip = {2,5,2,1,3};
    cout<<inversioncount(ip, 0, ip.size()-1);
    
    return 0;
}
