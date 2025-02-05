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

        vector<string> adj(n);

        for(int i=0;i<n;i++) cin>>adj[i];

        // unordered_map<int,> m;

        
        vector<int> ans;
        ans.push_back(1);
        int cnt = 1;

        for(int i=2;i<=n;i++){
            vector<int> dum;
            bool flag = false;
            for(int j=ans.size()-1;j>=0;j--){
                int ele = ans[j];
                if(adj[ele-1][i-1]=='1' && !flag){
                    dum.push_back(i);
                    flag = true;

                }
                
                dum.push_back(ele);
                
            }
            if(!flag) dum.push_back(i);

            vector<int> dup;
            for(int j=dum.size()-1;j>=0;j--){
                dup.push_back(dum[j]);
            }
            ans = dup;
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;



        t--;
    }
    return 0;

} 