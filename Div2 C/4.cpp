#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

// bool comp(pair<int,int> a, pair<int,int> b){
//     if(a.first<b.first) return true;
//     if()
// }



// Driver Code 
int main() 
{ 
        int n;
        cin>>n;

        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;

            arr.push_back({a,b});
        }

        sort(arr.begin(),arr.end());

        int prev = -1;

        for(int i=0;i<n;i++){
            if(prev<=arr[i].second){
                prev = arr[i].second;
            }
            else prev = arr[i].first;
        }

        cout<<prev<<endl;




    return 0;

} 