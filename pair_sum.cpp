#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum){

	unordered_set<int> s;
	vector<int> result;
	
	for(int i=0;i<arr.size();i++)
	{
		int comp = Sum - arr[i];

		if(s.find(comp)!=s.end())
		{
			result.push_back(arr[i]);
			result.push_back(comp);
			return result;
		}
        
		s.insert(arr[i]);
	}
	return result;
}

int main()
{
    cout<<"Hello World";
    
    vector<int> v = {1,2,3,4,5,6,7};
    
    vector<int> v_res = pairSum(v, 10);
    
    cout<<v_res[0]<<v_res[1]<<endl;
    
    return 0;
}
