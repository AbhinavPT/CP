#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

int last_less_than_column(const vector<vector<int>>& matrix, int col, int target) {
    int n = matrix.size();
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid][col] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return high;  // Last element < target
}

int first_greater_column(const vector<vector<int>>& matrix, int col, int target) {
    int n = matrix.size();
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid][col] <= target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return low;  // First element > target
}



// Driver Code 
int main() 
{ 
    // int t;
    // cin>>t;
    // while(t>0){
        
        int n,k,q;
        cin>>n>>k>>q;

        vector<vector<int>> arr;

        for(int i=0;i<n;i++){
            vector<int> a(k,0);
            for(int j=0;j<k;j++){
                cin>>a[j];
            }
            arr.push_back(a);
        }

        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                arr[j][i] = arr[j][i]|arr[j-1][i];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        for(int i=0;i<q;i++){
            int m;
            cin>>m;

            int mini = 0;
            int maxi = n-1;



            for(int j=0;j<m;j++){
                int r,c;
                char s;
                cin>>r>>s>>c;

                if(s=='<'){
                    int l = last_less_than_column(arr,r-1,c);
                    maxi = min(maxi,l);
                    // cout<<"maxi "<<l<<" ";
                }
                else{
                    int l = first_greater_column(arr,r-1,c);
                    mini = max(mini,l);
                
                    // cout<<"mini "<<l<<" ";
                }

            }
            if(mini>maxi) cout<<-1<<endl;
            else cout<< mini+1<<endl;
        }
        
        

    //     t--;
    // }
    return 0;

} 