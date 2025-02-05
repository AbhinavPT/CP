#include <iostream> 
#include<vector>
#include <algorithm>
#include<set>
using namespace std; 

void fun(string s){
    set<pair<int,int>> pq;

    for(int i=0;i<s.size();i++){
        pq.insert({s[i]-'0',-1*i});
    }

    while(!pq.empty()){
        // auto front = pq.rbegin();

        auto it = pq.begin();
        // --it;
        int ind = -1*it->second;
        int val = it->first;
        pq.erase(it);


    

        // cout<<"ind "<<ind<<" val "<<val<<endl;

        if(ind>0 && s[ind-1]-'0'+1<val) {
            pq.erase({s[ind-1]-'0',-1*(ind-1)});
            s[ind] = s[ind-1];
            // cout<<s[ind]<<endl;
            s[ind-1] = val+'0'-1;
            pq.insert({s[ind-1]-'0',-1*(ind-1)});
            pq.insert({s[ind]-'0',-1*(ind)});
        }
    }
    cout<<s<<endl;
    return;

}
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        string s ; 
        cin>>s;

        // cout<<s<<endl;

        fun(s);
        t--;
    }
    return 0;

} 