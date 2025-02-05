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

        for(int i=0;i<n;i++) cin>>arr[i];

        // sort(arr.begin(),arr.end());

        int prev = arr[0];

        bool flag = false;

        for(int i=1;i<n;i++){
            if(arr[i]<2*prev && arr[i]*2>prev){
                flag = true;
                break;
            }
            prev = arr[i];
        }

        if(flag){
            cout<<"YES"<<endl;
            
        }
        else cout<<"NO"<<endl;


        t--;
    }
    return 0;

} 