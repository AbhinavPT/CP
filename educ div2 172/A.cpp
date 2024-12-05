#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
// #include <bits/stdc++.h>
#include <algorithm>

using namespace std; 

int addCoin(int n,int k, vector<int> arr){

    sort(arr.begin(),arr.end(),greater<int>());

    for(int i=0;i<n;i++){
        if(arr[i]<=k) k-= arr[i];
        else{
            return k;
        }
    }
    return k;
    
}

// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n,k;
        cin>>n>>k;

        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int score = addCoin(n,k, arr);

        cout<<score<<endl;

        t--;
    }
    return 0;

} 