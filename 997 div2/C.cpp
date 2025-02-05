#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>
#include<set>

using namespace std; 




// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;

        int cnt=2;

        for(int i=0;i<n;i++){
            if(i==0 || i==2 || i==n-1){
                cout<<1<<" ";
            }
            else {
                cout<<cnt<<" ";
                cnt++;
            }
        }

        t--;

        
    }
    return 0;

} 