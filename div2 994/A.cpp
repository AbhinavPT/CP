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

        vector<int> arr(n);

        bool allzero = true;
        int cntnonzero = 0;
        bool consnonzero = true;

        for(int i=0;i<n;i++){
            cin>>arr[i];

            if(arr[i]!=0){
                 allzero = false;
                 cntnonzero++;
                 if(cntnonzero>1){
                    if(arr[i-1]==0) consnonzero = false;
                 }
            }
            
        }

        if(allzero) cout<<0<<endl;
        else if(consnonzero) cout<<1<<endl;
        else cout<<2<<endl;

        t--;
    }
    return 0;

} 