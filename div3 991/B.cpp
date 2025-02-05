#include <iostream> 
#include<vector>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int n ;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        long long odds = 1ll*(n+1)/2;
        // cout<<"odds "<<odds<<endl;
        long long evens = 1ll*n/2;
        // cout<<"evens "<<evens<<endl;

        long long sumodd = 0;
        long long sumeven = 0;

        for(int i=0;i<n;i++){
            if(i%2==0) sumodd+= 1ll*arr[i];
            // cout<<"sumodd "<<sumodd<<endl;
            else sumeven += 1ll*arr[i];
            // cout<<"sumeven "<<sumeven<<endl;
        }

        if(sumodd%odds==0 && sumeven%evens==0 && sumodd/odds==sumeven/evens){
            
            
             cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

        t--;
    }
    return 0;

} 