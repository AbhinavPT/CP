#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

void findind(int n,int k, vector<int> arr){
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        m[arr[i]%k]++;
    }
    for(int i=0;i<n;i++){
        if(m[arr[i]%k]<=1){
            cout<<"YES"<<endl;
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}


// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n,k;
        cin>>n>>k;

        
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        findind(n,k,arr);

        t--;
    }
    return 0;

} 