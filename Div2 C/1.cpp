#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 



void find(int m, int k){

    if(m==1 && k==0){
         cout<<0<<" "<<0;
         return;
    }

    long long mini = -1;
    long long maxi = -1;
    bool flag = true;

    vector<int> small(m,0);
    vector<int> large(m,0);

    small[0] = 1;

   

    int rem = k - 1;
    int i = m-1;

    if(rem<0) {
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    while(rem>0 && i>=0){

        int toadd = max(0,min(9-small[i],rem));
        // cout<<"toadd"<<" "<<toadd<<" "<<endl;
        small[i]+=toadd;
        // cout<<"digit"<<" "<<i<<" "<<small[i]<<" "<<endl;
        rem-= toadd;
        i--;
    }

    if(rem!=0){
        cout<<mini<<" ";
    }



    else if(rem==0){
        // mini = 0;

        for(int i=0;i<m;i++){
            cout<<small[i];
        }
        cout<<" ";

       

    }
    rem = k;
    i = 0;

    while(rem>0 && i<m){

        int toadd = max(0,min(9-large[i],rem));
        // cout<<"toadd"<<toadd<<" ";
        large[i]+=toadd;
        rem-= toadd;
        i++;
    }

    if(rem!=0){
        cout<<maxi;
    }

    else if(rem==0){
        maxi = 0;
        for(int i=0;i<m;i++){
            cout<<large[i];
        }
        cout<<" ";
    }



    // cout<<mini<<" "<<maxi<<endl;
}


// Driver Code 
int main() 
{ 
    // int t;
    // cin>>t;
    // while(t>0){
        
        int m,k;
        cin>>m>>k;

        
        find(m,k);

    //     t--;
    // }
    return 0;

} 