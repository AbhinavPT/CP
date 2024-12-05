#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<set>
#include<queue>
// #include <bits/stdc++.h>
#include <algorithm>

using namespace std; 

void lexi(int n, vector<int> arr){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // set<pair<long long,long long>> s;

    // vector<long long> tosort;
    vector<int> ans;

    for(int i=0;i<n;i++){
        pq.push({arr[i],i});
        // s.insert({arr[i],i});
    }

    int currInd = 0;
    int lastInd = n;

    while(!pq.empty()){
        auto mini = pq.top();
        pq.pop();

        if(mini.second>=currInd){
            currInd = mini.second;
            ans.push_back(mini.first);

        }
        else{
            int ind = mini.second;
            arr.push_back(arr[ind]+1);
            pq.push({arr[ind]+1,lastInd});
            lastInd++;
        }

    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return ;




    
}

// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;

        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        lexi(n, arr);

        // cout<<score<<endl;

        t--;
    }
    return 0;

} 