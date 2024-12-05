#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>

using namespace std; 

void changedTo(string s , int n){

    int mini = INT_MAX;
    int maxi = INT_MIN;

    char minic  = '#';
    char maxic = '$';

    unordered_map<char,int> m;
    // m[minic] = 1000;
    // m[maxic] = -1000;

    for(int i=0;i<n;i++){
        m[s[i]]++;

    }

    for(auto it : m){
        // m[s[i]]++;

        if(m.size()==1) {
            minic = it.first;
            maxic = it.first;
            break;
        }

        int cnt =it.second;
        char c = it.first;

        if(mini>=cnt){
            mini = cnt;
            minic = c;
        } 
        if(maxi<cnt){
            maxi = cnt;
            maxic = c;
        }
    }

    if(minic==maxic && m.size()>1){
        bool flag1 = true;
        bool flag2 = true;
        for(int i=0;i<n;i++){
            if(mini == m[s[i]] && flag1){
                minic = s[i];
                flag1 = false;

            }
            else if(maxi==m[s[i]] && s[i]!=minic && flag2){
                maxic = s[i];
                flag2 = false;
            }

        }
    } 

    for(int i=0;i<n;i++){
        if(s[i]==minic){
            s[i] = maxic;
            break;
        }
    }

    cout<<s<<endl;


}


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

        changedTo( s ,  n);


        t--;
    }
    return 0;

} 