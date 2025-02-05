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

        for(int i=0;i<n;i++) cin>>a[i];

        bool flag = true;

        for(int i=0;i<n;i++){
            int mini = 2*max(i-0,n-i-1)+1;

            if(a[i]<mini) {
                flag = false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
        


        t--;
    }
    return 0;

} 