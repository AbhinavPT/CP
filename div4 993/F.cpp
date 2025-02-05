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
        
        int n,m,q;
        cin>>n>>m>>q;

        vector<int> a(n);
        int suma=0;
        int sumb = 0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            suma+= a[i];
        }
        vector<int> b(m);

        for(int i=0;i<m;i++){
            cin>>b[i];
            sumb+=b[i];
        }

        int tsum = 0;

        vector<int> rows(n);
        vector<int> cols(m);
        for(int i=0;i<n;i++){
            rows[i] = a[i]*sumb;
            tsum+= rows[i];
        }
        for(int i=0;i<m;i++){
            cols[i] = b[i]*suma;
        }

        set<pair<int,int>> s;

        for(int i=0;i<m;i++){
            s.insert({cols[i],i});
        }



        for(int i=0;i<q;i++){
            int x;
            cin>>x;

            int rem = tsum-x;

            for(int i=0;i<n;i++){
                
            }


        }




        

        t--;
    }
    return 0;

} 