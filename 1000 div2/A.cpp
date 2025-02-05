#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

        int a,b;
        cin>>a>>b;

        if(a==1 && b==1) {
            cout<<1<<endl;
        }

        else cout<<b-a<<endl;
        


        t--;
    }
    return 0;

} 