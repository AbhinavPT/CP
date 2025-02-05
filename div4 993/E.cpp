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
        
        long long k,r1,r2,l1,l2;
        cin>>k>>l1>>r1>>l2>>r2;

        // int n = 0;
        long long cnt = 0;

        long long f = 1;

        bool flag = true;
        long long b = 0;

        while(f<=(r2/l1)){
            long long nl2 = l2/f;
            long long nr2 = r2/f;

            if(l2%f!=0) nl2++;

            

            cnt+= max(b,(min(r1,nr2)-max(l1,nl2)+1));

            if(min(r1,nr2)-max(l1,nl2)+1<0) flag = false;

            // n++;
            f = f*k;
        }    

        cout<<cnt<<endl; 

        t--;
    }
    return 0;

} 