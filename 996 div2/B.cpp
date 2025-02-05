#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>
#include<set>

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

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        int cnt = 0;
        int def = 0;

        int mini = 1e9;

        for(int i=0;i<n;i++){
            if(a[i]<b[i]) {
                cnt++;
                def = b[i]-a[i];
            }
            else{
                mini = min(mini,a[i]-b[i]);
            }
        }

        if(cnt>1) {
            cout<<"NO"<<endl;
           
        }
        else {
            if(mini<def) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }





        t--;
    }
    return 0;

} 