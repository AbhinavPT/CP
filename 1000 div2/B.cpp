#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

       int n,l,r;

       cin>>n>>l>>r;

       vector<long long> a,b;

       for(int i=0;i<n;i++){

        int v;
        cin>>v;

        if(i<r){
            a.push_back(v);
        }
        if(i>=l-1){
            b.push_back(v);
        }
       }

       sort(a.begin(),a.end());
       sort(b.begin(),b.end());

       int len = r-l+1;

       long long sum1 = 0;
       long long sum2 = 0;

       for(int i=0;i<len;i++) sum1+= 1ll*a[i];
       for(int i=0;i<len;i++) sum2+= 1ll*b[i];

        cout<<min(sum1,sum2)<<endl;

        t--;
    }
    return 0;

} 