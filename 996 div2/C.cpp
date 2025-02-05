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
        
        int n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        vector<vector<long long>> arr(n,vector<long long>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        // cout<<endl;

        

        

        long long sum=0;

        if(n==m){
        if(s[0]=='D'){
            for(int i=0;i<m;i++){
                sum+= arr[0][i];
            }
        }
        else{
            for(int i=0;i<n;i++){
                sum+= arr[i][0];
            }
        }
        }

        int k=0;
        int i=0,j=0;
        // if(s[0]=='D') i++;
        // else j++;


        while(k<=s.size()){
            

            long long psum = 0;

            if(k==s.size() || s[k]=='D'){
                for(int l=0;l<m;l++){
                    psum+= arr[i][l];
                }
                arr[i][j] = sum-psum;
            }
            else{
                for(int l=0;l<n;l++){
                    psum+= arr[l][j];
                }
                arr[i][j] = sum-psum;
            }

            if(s[k]=='D'){
                i++;
            }
            else j++;
            k++;
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }



        t--;
    }
    return 0;

} 