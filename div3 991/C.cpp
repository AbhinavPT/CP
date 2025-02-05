#include <iostream> 
#include<vector>
#include <algorithm>
using namespace std; 

void fun(string a){
    long long sum = 0;
        int cnt3=0;
        int  cnt2=0;

        for(int i=0;i<a.size();i++){
            int digit = a[i]-'0';
            sum+= a[i]-'0';

            if(digit==3) cnt3++;
            else if(digit==2) cnt2++;

            
        }

        int mod = sum%9;
        // cout<<"mod "<<mod<<endl;
        if(mod==0){
            cout<<"YES"<<endl;
            return;
        }
        int rem = 9-mod;

        // cnt2 = min(9,cnt2);

        for(int i=0;i<=min(9,cnt2);i++){
            for(int j=0;j<=min(3,cnt3);j++){
                long long s = 1ll*i*2+1ll*j*6;
                // cout<<"s "<<s<<endl;

                if(s%9==rem) {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
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

        // long long n = a;

        fun(s);
        t--;
    }
    return 0;

} 