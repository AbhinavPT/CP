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
        
        int n,x,y;
        cin>>n>>x>>y;

        vector<int> arr(n,0);

        vector<int> prev(n,0);

        while(true){
            for(int i=0;i<n;i++){
                set<int> s;

                if(i!=0){
                    s.insert(arr[i-1]);
                }
                else{
                    s.insert(arr[n-1]);
                }

                if(i!=n-1){
                    s.insert(arr[i+1]);

                }
                else{
                    s.insert(arr[0]);
                }

                if(i==x-1){
                    s.insert(arr[y-1]);
                }
                else if(i==y-1){
                    s.insert(arr[x-1]);
                }

                // cout<<i<<endl;


                
                // for(auto it : s){
                //     cout<<it<<" ";
                // }
                // cout<<endl;

                // cout<<"elements in ";

                for(int j=0;j<4;j++){
                    
                    
                    if(s.find(j)==s.end()){
                        arr[i] = j;
                        break;
                    }
                    // else cout<<j<<" ";

                }
                // cout<<endl;
            }
            if(arr==prev){
                break;
            }
            prev = arr;
        }

        for(int i=0;i<n;i++){
            
            cout<<arr[i]%3<<" ";
        }
        cout<<endl;

        

        t--;
    }
    return 0;

} 