#include <iostream> 
using namespace std; 

int findm(int a , int b){
    int m = min(a,b);

    while(true){

        if(m%a==m%b) break;
        m++;
    }

    return m;
}
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int a ; int b;
        cin>>a>>b;

        int m = findm( a ,  b);

        cout<<m<<endl;

        t--;
    }
    return 0;

} 