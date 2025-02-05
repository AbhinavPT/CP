#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

int findind(int n){
    
    int sum = 1;
    int l=1;
    int r = 1;
    int cnt = 1;

    while(r<n){
        r = 2*(sum+1);
        cnt++;
        sum = r-l+1;
    }
    return cnt;
}


// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;

        
        // vector<int> arr(n);

        // for(int i=0;i<n;i++){
        //     cin>>arr[i];
        // }

        cout<<findind(n)<<endl;

        t--;
    }
    return 0;

} 