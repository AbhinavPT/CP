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

        string s;
        cin>>s;

        bool p = false;
        bool S = false;

        int cntp = 0;
        int cnts = 0;

        bool flag = false;

        for(int i=0;i<n;i++){
            if(s[i]=='p') {
                p = true;

            }
            else if(s[i]=='s'){
                S = true;
                if(p) {
                    flag = true;
                    break;
                }
            }

        }

        if(flag){
            cout<<"NO"<<endl;
            t--;
            continue;
        }


        if(!p || !S ) {
            cout<<"YES"<<endl;
             t--;
            continue;
        }

        s[0] = '.';
        s[n-1] = '.';

        for(int i=0;i<n;i++){
            if(s[i]=='p') {
                cntp++;

            }
            else if(s[i]=='s'){
                cnts++;
            }

        }

        if(cnts>0 && cntp>0){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }


        t--;
    }
    return 0;

} 