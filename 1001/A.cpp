#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

        string s;
        cin>>s;

        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
        }

        cout<<cnt<<endl;


        
        


        t--;
    }
    return 0;

} 