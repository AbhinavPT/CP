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
        
        int n,a,b;
        cin>>n>>a>>b;

        if(abs(a-b)%2==0){
            cout<<"YES"<<endl;
        }

        else cout<<"NO"<<endl;

        t--;
    }
    return 0;

} 