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

        vector<int> arr(n);
        unordered_map<int,int> m;

        for(int i=0;i<n;i++) {
            cin>>arr[i];
            m[arr[i]]++;
        }
        int cnt = 0;

        for(int i=0;i<n;i++) {
            int rem = k-arr[i];

            // int sum = m[rem]+m[arr[i]];
            bool flag = true;
            if(arr[i]==rem){
                if(m[arr[i]]<2){
                    flag = false;
                }
            }

            if(m[rem]>0 && m[arr[i]]>0 && flag ){


                m[arr[i]]--;
                m[rem]--;
                cnt++;


                // cout<<arr[i]<<" "<<rem<<endl;
            }
            else m[arr[i]]--;
        }

        cout<<cnt<<endl;

        t--;
    }
    return 0;

} 