#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        
        
        for(int i=0;i<n;i++) cin>>a[i];

        int maxi = n-k+1;

        if(maxi==1){
            int ind = 1;
            int cnt = 1;
            bool flag = true;
            for(int i=1;i<n;i+=2){
                if(a[i]!=ind){
                    flag = false;
                    cout<<cnt<<endl;
                    break;
                }
                cnt++;ind++;
            }
            if(flag) cout<<n/2+1<<endl;
        }
        else{
            bool flag = true;
            for(int i=1;i<=maxi;i++){
                if(a[i]!=1){
                    flag = false;
                    cout<<1<<endl;
                    break;
                }

            }
            if(flag) cout<<2<<endl;

        }
        
        


        t--;
    }
    return 0;

} 