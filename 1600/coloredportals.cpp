#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>
#include<set>

using namespace std; 

int find(int n, vector<pair<int,int>> adj[] , int src , int dst){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(n,0);
    vector<int> dist(n,1e9);

    vis[src] = 1;
    dist[src] = 0;
    pq.push({0,src});

    while (!pq.empty())
    {
        auto front = pq.top();
        int node  = front.second;
        int d = front.first;
        pq.pop();

        for(auto it : adj[node]){
            int wt = it.second;
            int adjNode = it.first;

            if(d+wt<dist[adjNode]){
                dist[adjNode] = d+wt;
                pq.push({dist[adjNode],adjNode});

                // if(adjNode==dst) return dist[adjNode];

            }
        }
    }
    if(dist[dst]<1e9) return dist[dst];
    return -1;
}




// Driver Code 
int main() 
{ 
    int t;
    cin>>t;

    int a,b;
    int s=t;
    while(t>0){
        
        int n,q;
        cin>>n>>q;

        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<pair<int,int>> *adj = new vector<pair<int,int>>[n];
      


        for(int i=0;i<n;i++){
            char f = arr[i][0];
            char s = arr[i][1];

            // cout<<f<< " "<<s<<" ";

            for(int j=i+1;j<n;j++){
                char f2 = arr[j][0];
                char s2 = arr[j][1];

                
            // cout<<f2<< " "<<s2<<" ";

                int wt = j-i;

                if(f2==f || f2==s || s2==f || s2==s){
                    adj[i].push_back({j,wt});
                    adj[j].push_back({i,wt});
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
                // cout<<adj[i][j].first<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;

            cout<<find(n,adj,a-1,b-1)<<endl;
        }


        t--;
    }
    return 0;

} 