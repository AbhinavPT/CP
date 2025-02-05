#include <iostream> 
#include<vector>
using namespace std; 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t>0){
        int a ; int b;
        cin>>a>>b;

        vector<int> size;

        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            size.push_back(s.size());

        }
        int cnt = 0;
        for(int i=0;i<a;i++){
            if(b>=size[i]){
                b = b-size[i];
                cnt++;
            }
            else break;
        }
        cout<<cnt<<endl;

        t--;
    }
    return 0;

} 