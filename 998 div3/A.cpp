#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

        vector<int> a(5);
        
        for(int i=0;i<5;i++){

            if(i==2){
                a[i] = a[i-1]+a[i-2];
            }
            else cin>>a[i];
        }
        int maxi = 0;
        int cnt = 0;

        for(int i=0;i<=2;i++){
            if(a[i+2]==(a[i+1]+a[i])) cnt++;
            
        }
        maxi = max(maxi,cnt);

        cnt = 0;
        a[2] = a[3]-a[1];
         for(int i=0;i<=2;i++){
            if(a[i+2]==(a[i+1]+a[i])) cnt++;
            
        }
        maxi = max(maxi,cnt);

        cnt = 0;
        a[2] = a[4]-a[3];

        for(int i=0;i<=2;i++){
            if(a[i+2]==(a[i+1]+a[i])) cnt++;
            
        }
        maxi = max(maxi,cnt);

        cout<<maxi<<endl;



        


        t--;
    }
    return 0;

} 