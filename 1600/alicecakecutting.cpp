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
        
        int n,m,v;
        cin>>n>>m>>v;

        
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> pref(n,0);
        vector<int> suff(n+1,0);

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(i>0) pref[i] = pref[i-1];

            cnt+= arr[i];

            if(cnt>=v){
                pref[i]+=1;
                cnt=0;
            }
            // cout<<pref[i]<<" ";

        }
        // cout<<endl;
        
        cnt = 0;

        for(int i=n-1;i>=0;i--){
            if(i<n-1) suff[i] = suff[i+1];

            cnt+= arr[i];

            if(cnt>=v){
                suff[i]+=1;
                cnt=0;
            }
            
        }
        
        // for(int i=0;i<n;i++) cout<<pref[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<=n;i++) cout<<suff[i]<<" ";
        // cout<<endl;
        long long maxi = -1;

        if(suff[0]<m && pref[n-1]<m) {
            cout<<-1<<endl;
            t--;
            continue;
        }

        int i = -1;
        int j = 0;

        
        long long sum = 0;
        while(j<=n){
                
            int f = 0;
            int s = suff[j];
            if(i>-1) f = pref[i];

            while(f+s<m && i+1<j){
                i++;
                sum -= 1ll*arr[i];
                f = pref[i];
                // cout<<"i "<<i<<" ";
                // cout<<"f "<<f<<" ";
            }
            // cout<<endl;

            if(f+s>=m){
                maxi = max(maxi,sum);
                // cout<<"sum "<<sum<<" ";

            }
            // cout<<endl;
            if(j<n) sum+= 1ll*arr[j];

            j++;
        }
        j = n;
        while(i<n-1){
            int f = 0;
            // int s = suff[j];
            if(i>-1) f = pref[i];
            i++;
                
            sum -= 1ll*arr[i];
            f = pref[i];
                // cout<<"i "<<i<<" ";
                // cout<<"f "<<f<<" ";
            
            // cout<<endl;

            if(f>=m){
                maxi = max(maxi,sum);
                // cout<<"sum "<<sum<<" ";

            }
        }

        cout<<maxi<<endl;

        t--;
    }
    return 0;

} 