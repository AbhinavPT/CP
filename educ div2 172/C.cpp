#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
// #include <bits/stdc++.h>
#include <algorithm>

using namespace std; 

int findG(int n,int k, string s){

    if(s.size()!=n ) return -1;



    vector<int> suff;
    int f1 = 0;
    int f0 = 0;

    for(int i=n-1;i>0;i--){
        if(s[i]=='1')f1++;
        else if(s[i]=='0') f0++;

        // if(i!=n-1) suff[i]+= suff[i+1];
        suff.push_back(f1-f0);


    }
    
    sort(suff.begin(),suff.end(),greater<int>());

    long long sum = 0;
    int m = 1;

    for(auto i : suff){
        sum += 1ll*i;
        m++;
        if(sum>=k) return m;
    }

    return -1;


    
}

// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        int m = findG(n,k, s);

        cout<<m<<endl;

        t--;
    }
    return 0;

} 