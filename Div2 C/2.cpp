#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 



long long findways(int n, vector<int> arr){

    
    vector<int> pref(n,0);
    vector<int> suff(n,0);

    long long sum = 0;

    for(int i=0;i<n;i++){
        sum+= 1ll*arr[i];
        
    }
    // cout<<"sum"<<" "<< sum<<endl;

    if(sum%3!=0) {
        return 0;
    }

    long long reqSum = sum/3;
    // cout<<"reqsum"<<" "<< reqSum<<endl;

    sum = 0;

    for(int i=0;i<n;i++){
        if(i>0){
            pref[i] = pref[i-1];
        }

        sum+= 1ll*arr[i];
        // cout<<"sum"<<" "<< sum<<endl;

        if(sum==reqSum){
            pref[i]++;
        }

    }

    sum = 0;

    for(int i=n-1;i>=0;i--){
        if(i<n-1){
            suff[i] = suff[i+1];
        }

        sum+= 1ll*arr[i];
        // cout<<"sum"<<" "<< sum<<endl;

        if(sum==reqSum){
            suff[i]++;
        }

    }
    long long maxi = 0;
    int prev = 0;
    for(int i=0;i<n-2;i++){
        if(pref[i]>prev){
            prev = pref[i];
            maxi += 1ll*suff[i+2];
        }
    }

    return maxi;

    // cout<<mini<<" "<<maxi<<endl;
}


// Driver Code 
int main() 
{ 
        int n;
        cin>>n;

        vector<int> arr(n,0);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        
        cout<<findways(n,arr)<<endl;


    return 0;

} 