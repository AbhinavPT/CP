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

        vector<int> a(n);
        vector<int> b(n);

        int cnt1 =1, cnt2 = 1;

        int p = -1; int q = -1;

        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
            
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1])cnt1++;
            if(b[i]!=b[i-1]) cnt2++;
        }



        if(cnt1+cnt2>3){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;

        
        


        t--;
    }
    return 0;

} 