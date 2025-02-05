#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){

        long long n;
        cin>>n;

        vector<vector<long long>> a(n,vector<long long>(n));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        vector<int> b(n);

        for(int i=0;i<n;i++){
            long long cnt = 0;
            for(int j=n-1;j>=0;j--){
                if(a[i][j]==1)cnt++;
                else break;
            }
            b[i] = cnt;
        }

        sort(b.begin(),b.end());

        // if(b[0]!=0){
        //     b.pop_back();
        //     b.push_back(0);
        // }
        // sort(b.begin(),b.end());

        long long num = 0;
        long long i=0;
        long long end = n-1;

        int cnt = 0;


        while(i<=end){
            if(b[i]>=num){
                num++;
            }
            i++;
        }


        // int ans = -1;

        // for(int i=1;i<n;i++){
        //     if(b[i]-b[i-1]>1){
        //         ans = b[i-1]+1;
        //         break;
        //     }
        //     ans = b[n-1]+1;
        // }
        
        // if(ans==-1) ans = n;

        cout<<num<<endl;

        t--;
    }
    return 0;

} 