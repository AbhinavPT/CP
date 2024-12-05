#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>

using namespace std; 

int count(int n, vector<vector<int>> arr){

    int sum = 0;
    int secMax = -1e9;

    for(int i=0;i<n;i++){
        sum += max(arr[i][0],arr[i][1]);
        secMax = max(secMax,min(arr[i][0],arr[i][1]));
    }

    return sum+secMax;
}

// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;

        vector<vector<int>> arr(n,vector<int>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>arr[j][i];
            }
        }

        int score = count(n, arr);

        cout<<score<<endl;

        t--;
    }
    return 0;

} 