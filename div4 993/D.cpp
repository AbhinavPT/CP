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

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        set<int> s;

        // int num = 1;

        for(int i=1;i<=n;i++){
            s.insert(i);
            
        }

        for(int i=0;i<n;i++){
            if(s.find(arr[i])!=s.end()){
                s.erase(arr[i]);
            }
            else {
                arr[i] = *s.begin();
                s.erase(s.begin());
            }
            
        }


        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;



        t--;
    }
    return 0;

} 