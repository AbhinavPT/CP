#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>
#include<set>

using namespace std; 

long long split(int l,int r, int k){

    int len = r-l+1;
    long long cnt = 0;

    if(r-l+1<k){
        return 0;
    }

    int m = (l+r)/2;

    if(len%2==0){
        cnt+= split(l,m,k);
        cnt+= split(m+1,r,k);
    }

    else{
        cnt+= 1ll*m;
        cnt+= split(l,m-1,k);
        cnt+= split(m+1,r,k);
    }

    return cnt;
}



// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n,k;
        cin>>n>>k;

        // cout<<split(1,n,k)<<endl;

        int val = 0;

        int len = n;

        while(n>=k){
            if(n%2==1){
                val = (n+1)/2;

            }
            n/=2;
        }

        int rem = len/val;

        long long ans = 1ll*val*rem*(rem+1)/2;

        cout<<ans<<endl;
        



        t--;
    }
    return 0;

} 