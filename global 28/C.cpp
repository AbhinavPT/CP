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
        
        string s;
        cin>>s;

        int n = s.size();
        int l=-1,r=-1;

        cout<<"1 "<<n<<" ";

        int ind = -1;

        for(int i=0;i<n;i++){
            if(s[i]=='0') {
                ind = i;
                break;
            }
        }

        if(ind==-1){
            cout<<"1 "<<"1 "<<endl;
            t--;
            continue;
        }

        int len = n-ind;

        int low = 0;
        int high = len-1;

        int maxi = -1;

        while(high<n){
            int cnt = 0;

            int j = low;

            for(int i=ind;i<n;i++){
                if(s[j]!=s[i]){

                cnt++;
                j++;
                }
                else break;
            }

            if(cnt>maxi){
                maxi = cnt;
                l = low+1;
                r = high+1;
            }
            low++;
            high++;

        }

        cout<<l<<" "<<r<<" "<<endl;




        t--;
    }
    return 0;

} 