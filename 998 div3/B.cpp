#include <bits/stdc++.h>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> arr(n,vector<int>(m));

        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];

                if(arr[i][j]<n){
                    ans[arr[i][j]] = i;
                }
            }
        }

        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
        }

        sort(arr.begin(),arr.end(),[](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
        });

        int cnt = 0;
        bool flag = true;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(arr[i][j]!=cnt){
                    cout<<-1<<endl;
                    flag = false;
                    break;
                }
                cnt++;
            }
            if(!flag) break;
        }

        if(flag){
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
        }






        t--;
    }
    return 0;

} 