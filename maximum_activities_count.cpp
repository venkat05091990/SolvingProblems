#include<bits/stdc++.h>
using namespace std;

bool compare_pair(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int countActivites(vector<pair<int,int> > activities){
    int n=activities.size();

    //sort pairs by finish time O(NLOGN)
    sort(activities.begin(), activities.end(), compare_pair);
    
    //output default taking first activity
    int op=1;
    int curr_activity_end_time = activities[0].second;
    
    //main logic O(N)
    int c = 1;
    while(c<n){
        if(activities[c].first>=curr_activity_end_time){
            op++;
            curr_activity_end_time = activities[c].second;
        }
        c++;
    }
    
    return op;
}

int main()
{
    vector<pair<int,int>> v = {{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};

    cout<<countActivites(v);
    return 0;
}
