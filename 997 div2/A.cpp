#include<iostream>
#include<vector>
using namespace std;

//Stair, Peak, or Neither?
int main(){
    int t;
    cin >>t;
    while(t--){
        int m,n,x;
        int diff = 0;
        cin >> n >> m;
        vector<int> v;
        for(int i=0; i<2*n; i++){
            cin >> x;
            v.push_back(x);
        }    
        int sum = m*n*4;
        for(int i=2; i<2*n; i+=2){
            //cout << v[i]<< " " <<v[i+1]<<endl;
            diff+= abs(2*m - v[i]-v[i+1]);
            //cout << "diff" << diff<<endl;
        }
        cout << sum - 2*diff << endl;
    }

}