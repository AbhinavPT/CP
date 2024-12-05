#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>

using namespace std; 

bool isPerfect(int sum){
    double rootval = sqrt(sum);
    int val = static_cast<int>(rootval);

    if(rootval==val && val%2==1) return true;
    return false;
}


int count(int n, vector<int> arr){

    int cnt = 0;
    int num = 1;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum+= arr[i];
        if(isPerfect(sum)) cnt++;
    }

    return cnt;
    
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

        int score = count(n, arr);

        cout<<score<<endl;

        t--;
    }
    return 0;

} 