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

        multiset<int> s;

        vector<int> l(n);
        vector<int> r(n);

        for(int i=0;i<n;i++) {
            cin>>l[i];
            cin>>r[i];

            if(l[i]==r[i]){
                s.insert(l[i]);
            }
        }

        vector<int> pref(2*n+1,0);

        for(int i=1;i<=2*n;i++){
            if(s.find(i)==s.end()){
                pref[i] = pref[i-1];
            }
            else {
                pref[i] = 1+pref[i-1];
            }
        }

        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(l[i]==r[i]){
                if(s.count(l[i])>1)ans[i] = 0;
                else ans[i] = 1;
            }
            else {
            // int low = *s.lower_bound(l[i]);
                    if(pref[r[i]]-pref[l[i]-1]==r[i]-l[i]+1){
                        ans[i] = 0;
                    }
                    else {
                        ans[i] = 1;
                    }
            }
        }

        for(int i=0;i<n;i++) cout<<ans[i];

        cout<<endl;


        t--;
    }
    return 0;

} 