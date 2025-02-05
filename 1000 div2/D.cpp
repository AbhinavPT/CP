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

        vector<long long> a(n);
        vector<long long> b(m);

        vector<long long> prea;
        vector<long long> preb;

        for(int i=0;i<n;i++){
            // long long s;
            cin>>a[i];

           
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

        int kmax = min(n,min(m,(n+m)/3));

        vector<long long> ans;

        // // cout<<"kmax "<<kmax<<endl;

        // int fk = min(n,m)/2 + min(n,m)%2;

        
        // // set<long long> da = a;
        // // set<long long> db = b;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long long prev = 0;

        
        // cout<<"prefa ";
        for(int i=0;i<n/2;i++){
            prev+= a[n-i-1]-a[i];
            prea.push_back(prev);

            // cout<<prea[i]<<" ";
            
        }
        // cout<<endl;
        prev = 0;

        // cout<<"prefb ";
        for(int i=0;i<m/2;i++){
            prev += b[m-i-1]-b[i];
            preb.push_back(prev);

            // cout<<preb[i]<<" ";
        }

        for(int k=1;k<=kmax;k++){
            int l = max(0,2*k-m);
            int r = min(k,n-k);

            // l--;
            // r--;

            long long answ;

            while(l<=r){
            

            int mid1 = (2*l+r)/3;
            int mid2 = (2*r+l)/3;

            long long f1 = prea[mid1]+preb[k-mid1];
            long long f2 = prea[mid2]+preb[k-mid2];

            if(f1>f2){
                answ = f1;
                r = mid2;
            }
            else {
                answ = f2;
                l = mid1;
            }

            }
            ans.push_back(answ);

        }




        cout<<kmax<<endl;

        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;

        // cout<<n<<" "<<m<<endl;

        t--;
    }
    return 0;

} 