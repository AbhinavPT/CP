#include <bits/stdc++.h>
using namespace std; 

void dfs(int src,set<int> adjg[], vector<int> &vis,set<int> &st){
    vis[src] = 1;

    st.insert(src);

    for(int it : adjg[src]){
        if(!vis[it]){
            dfs(it,adjg,vis,st);
        }
    }

    return;
}

void dfs2(int src,set<int> adjg[], vector<int> &vis){
    vis[src] = 1;

    // st.insert(src);

    for(int it : adjg[src]){
        if(!vis[it]){
            dfs2(it,adjg,vis);
        }
    }

    return;
}
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int n,m1,m2;
        cin>>n>>m1>>m2;

        set<int> adjf[n+1];
        set<int> adjg[n+1];

        for(int i=0;i<m1;i++){
            int u,v;
            cin>>u>>v;

            adjf[u].insert(v);
            adjf[v].insert(u);
        }

        for(int i=0;i<m2;i++){
            int u,v;
            cin>>u>>v;

            adjg[u].insert(v);
            adjg[v].insert(u);
        }

        // for(int i=1;i<=n;i++){
        //     cout<<i<<" -> ";
        //     for(int it : adjf[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=1;i<=n;i++){
        //     cout<<i<<" -> ";
        //     for(int it : adjg[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> vis(n+1,0);


        vector<set<int>> comp;

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                set<int> st;
                dfs(i,adjg,vis,st);
                comp.push_back(st);
            }
        }



        int numcomp = comp.size();
        int cnt = 0;

        // for(int i=0;i<numcomp;i++){
        //     cout<<i<<" -> ";
        //     for(int src : comp[i]){
        //         cout<<src<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<numcomp;i++){
            // cout<<i
            for(int src : comp[i]){
                // cout<<src<<" ";
                vector<int> rem;
                for(int it : adjf[src]){
                    
                    if(comp[i].find(it)==comp[i].end()){
                        rem.push_back(it);
                        cnt++;
                    }
                }

                for(int j=0;j<rem.size();j++){
                    adjf[src].erase(rem[j]);
                    adjf[rem[j]].erase(src);
                }
            }
        }
        // cout<<"cnt "<<cnt<<" ";

        //   for(int i=1;i<=n;i++){
        //     cout<<i<<" -> ";
        //     for(int it : adjf[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=1;i<=n;i++){
        //     cout<<i<<" -> ";
        //     for(int it : adjg[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }


         vector<int> vis2(n+1,0);

         int cntf = 0;


        for(int i=1;i<=n;i++){
            if(!vis2[i]){
                dfs2(i,adjf,vis2);
                cntf++;
            }
        }

        // cout<<"cntf "<<cntf<<" numcomp "<<numcomp<<endl;

        cnt+= cntf-numcomp;

        cout<<cnt<<endl;


        t--;
    }
    return 0;

} 