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
        
        int n,k;
        cin>>n>>k;

        vector<int> arr(n,0);

        int num = 1;

        for(int i=0;i<n;i++){
            int ind = i+1;

            if(ind%k==0){
                 arr[i] = num;
                 num++;
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i] = num;
                 num++;
            }
            cout<<arr[i]<<" ";
        }
        cout<<endl;



        



        t--;
    }
    return 0;

} 