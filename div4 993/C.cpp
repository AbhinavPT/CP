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
        
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        int row1 = min(m,a);
        int row2 = min(m,b);
        int rem = 2*m-row1-row2;

        int occ = min(c,rem);

        cout<<row1+row2+occ<<endl;        

        t--;
    }
    return 0;

} 