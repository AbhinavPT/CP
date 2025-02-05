#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag = true;

        for(int i=0;i<n-1;i++){
            int f = i;
            int s = i+1;

            if(arr[f]>arr[s]){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }

            int mini = min(arr[f],arr[s]);
            arr[f]-= mini;
            arr[s]-= mini;

        }

        if(flag) cout<<"YES"<<endl;



        t--;
    }
    return 0;

} 