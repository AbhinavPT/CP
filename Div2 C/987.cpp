#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

void fillit(int n){
    if(n%2==1 && n<=25){
        cout<<-1<<endl;
        return;
    } 
    if(n%2==0){
        int i = 1;

        for(int i=1;i<=n/2;i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(n%2==1 && n>25){
        int cnt = 1;

        for(int i=1;i<=n;i++){
            if(i==1 || i==17 || i==26){
                cout<<1<<" ";
            }
            else if(i==2 || i==27){
                cout<<2<<" ";
            }
            else if(i<17){
                int num = (i+3)/2;
                cout<<num<<" ";
            }
            else if(i>17 && i<26){
                int num = (i+2)/2;
                cout<<num<<" ";
            }
            else {
                int num = (i)/2;
                cout<<num<<" ";
            }
        
        }
    }

}



// Driver Code 
int main() 
{ 
    
    int t;
    cin>>t;

    while(t>0){

        int n;

        cin>>n;

        fillit(n);

        t--;
    }


    return 0;

} 