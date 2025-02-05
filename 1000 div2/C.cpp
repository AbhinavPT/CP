#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
 
 
        vector<vector<int>> adj(n+1, vector<int>());
        vector<int> deg(n+1, 0);
 
 
        for(int i = 0; i < n-1; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
 
 
        vector<int> nodes(n);
        for(int i = 0; i < n; ++i){
            nodes[i] = i + 1;
        }
 
 
        sort(nodes.begin(), nodes.end(), [&](const int a, const int b) -> bool{
            if(deg[a] != deg[b]) return deg[a] > deg[b];
            return a < b;
        });
 
 
        for(int v = 1; v <= n; ++v){
            sort(adj[v].begin(), adj[v].end());
        }
 
        long long max_val = 0;
 
 
        for(int i = 0; i < n; ++i){
            int u = nodes[i];
            for(int j = i + 1; j < n; ++j){
                int v = nodes[j];
 
                if(!binary_search(adj[u].begin(), adj[u].end(), v)){
                    long long temp = static_cast<long long>(deg[u]) + deg[v] - 1;
                    max_val = max(max_val, temp);
                    break; 
                }
            }
        }
 
        long long maxA = 0;
 
 
        for(int u = 1; u <= n; ++u){
            for(auto &v : adj[u]){
                if(u < v){ 
                    long long temp = static_cast<long long>(deg[u]) + deg[v] - 2;
                    maxA = max(maxA, temp);
                }
            }
        }
 
 
        cout << max(max_val, maxA) << "\n";
    }
 
    return 0;
}