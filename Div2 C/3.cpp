#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 





// Driver Code 
int main() 
{ 
        int n,m;
        cin>>n>>m;

        int rln = m+1;
        int rlm = 2*n+2;

        if(n>rln || m>rlm) {
            cout<<-1<<endl;
            return 0;
        }

        if(m<=n){
            while(m>0){
                cout<<"01";
                m--;
                n--;
            }
            if(n>0) cout<<"0";
            return 0;
        }

        int fr1 = n+1;
        int sr1 = m-(n+1);

        while(n!=0){
            if(sr1>0){
                cout<<"1";
                sr1--;
                
            }
            cout<<"10";
            n--;
            fr1--;
        }
        if(fr1) cout<<"1";
        if(sr1) cout<<"1";



    return 0;

} 