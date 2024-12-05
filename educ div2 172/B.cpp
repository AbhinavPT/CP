#include <iostream> 
#include <set>
#include <vector>
#include<unordered_map>
using namespace std; 

int findScore(int n, vector<int> arr){

    // priority_queue<pair<int,int>> pq;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    int cnt = 0;

    for(auto it : m){
        if(it.second==1) cnt++;
    }

    int scoreAlice = 2* ((cnt+1)/2);

    scoreAlice += m.size()-cnt;

    return scoreAlice;
}

// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;

        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int score = findScore(n, arr);

        cout<<score<<endl;

        t--;
    }
    return 0;

} 