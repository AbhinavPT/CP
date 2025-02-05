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
        
        string a;
        cin>>a;

        reverse(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            if(a[i]=='p') a[i] = 'q';
            else if(a[i]=='q') a[i] = 'p';
        }
        cout<<a<<endl;

        t--;
    }
    return 0;

} 