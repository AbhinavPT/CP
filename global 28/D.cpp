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
        
        int n,m;
        cin>>n>>m;

        multiset<int> a;
        vector<int> aarr(n);
        int k_rat ;
        cin>>k_rat;

        a.insert(k_rat);

        for(int i=1;i<n;i++){
            int x ;
            cin>>x;
            a.insert(x);
            aarr[i] = x;
        }

        multiset<int> b;
        vector<int> barr(m);
        for(int i=0;i<m;i++){
            int x ;
            cin>>x;
            b.insert(x);
            barr[i] = x;
        }

        sort(aarr.begin(),aarr.end());
        sort(barr.begin(),barr.end());

        auto ub = a.upper_bound(k_rat);
        int ind = distance(a.begin(),ub);

        for(int k=1;k<=m;k++){

            int sum = 0;

            auto ubq = b.upper_bound(k_rat);
            int lsum = distance(b.begin(),ubq);
            
            sum+= lsum/k;

            int lrem= lsum%k;
            int rrem = (k-lrem)%k;

            if(k==1) cout<<"rrem"<<rrem<<" ";

            int torem = m%k;
            ind+= torem;

            if(k==1) cout<<"ind"<<ind<<" ";
            

            for(int i=ind;i<m-rrem;i+=k){
                int ele = barr[i];
                int lbi = distance(a.begin(),a.lower_bound(ele));
                if(k==1) cout<<"lbi"<<lbi<<" ";
                sum+= n-lbi+1;
            }

            if(rrem>0){
            int ele = barr[m-rrem];
            int lbi = distance(a.begin(),a.lower_bound(ele));
            sum+= n-lbi+1;
            }


            cout<<sum<<" ";


        }
        cout<<endl;
        t--;
    }
    return 0;

} 