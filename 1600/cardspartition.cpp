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

    int a,b;
    int s=t;
    while(t>0){
        
        long long n,k;
        cin>>n>>k;

        if(t==s){
            a = n;
            b = k;
        }
        // if(t==(s-474) && a==4 && b==17){
        //     cout<<k;
        //     return 0 ;
        //     // <<" k "<<k<<endl;
        // }

        
        vector<long long> arr(n);
        long long sum = 0;
        long long maxi = 0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+= arr[i];
            maxi = max(maxi,arr[i]);

            // if(t==(s-474) && a==4 && b==17){
            // cout<<arr[i]<<" ";
            // }

        }
        long long tsum = sum;
        sum+= k;

        long long possible =1;

        for(long long i=1;i<=n;i++){
            long long val = sum/i;
            long long rem = sum%i;

            if(val>=maxi){

                if(rem<=k) possible = i;
            }
            else{
                break;
            }
        }

        cout<<possible<<endl;

        t--;
    }
    return 0;

} 