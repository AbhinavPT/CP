#include <iostream> 
using namespace std; 

int findm(int n , int m, int k,string s){
    int ans1 = 0;

    // bool flag = false;
    int cntzero = 0;

    // int firstzero = -1;
    // int lastzero = -1;

    for(int i=0;i<n;i++){
        if(s[i]=='0') {
             cntzero++; 
        }
        else cntzero = 0;

        if(cntzero==m){
            // if(!flag){

            // }
            // else{

            // }
            // cntzero = 0;
            ans1++;
            i += k-1;
            cntzero = 0;
        }
    }

    int ans2 = 0;
    cntzero = 0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='0') {
             cntzero++; 
        }
        else cntzero = 0;

        if(cntzero==m){
            // if(!flag){

            // }
            // else{

            // }
            // cntzero = 0;
            ans2++;
            i -= k-1;
            cntzero = 0;
        }
    }
    int ans = min(ans1,ans2);

    return ans1;
}
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int n ; int m; int k;
        string s;
        cin>>n>>m>>k;
        cin>>s;

        int ans = findm( n,m,k,s);

        cout<<ans<<endl;

        t--;
    }
    return 0;

} 