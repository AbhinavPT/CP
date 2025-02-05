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
        
        int n;
        cin>>n;

        
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        set<int> zero;
        set<int> one;
        set<int> two;

        int cnt0 = 0,  cnt1 = 0, cnt2 = 0;

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cnt0++;
                zero.insert(i);
            }
            else if(arr[i]==1){
                cnt1++;
                one.insert(i);
            }
            else{
                cnt2++;
                two.insert(i);
            }
        }

        int ind = n-1;
        int k = 0;
        vector<pair<int,int>> ans;

        while(ind>=0){

            if(!two.empty()){
                if(arr[ind]==2){
                    two.erase(ind);

                }
                else if(arr[ind]==1){
                    int ftwo = *two.begin();
                    swap(arr[ind],arr[ftwo]);

                    two.erase(ftwo);
                    // two.insert(ind);

                    one.erase(ind);
                    one.insert(ftwo);

                    k++;
                    ans.push_back({ftwo,ind});
                }
                else{
                    int fone = *one.begin();
                    int ftwo = *two.begin();

                    swap(arr[ind],arr[fone]);
                    swap(arr[ind],arr[ftwo]);

                    zero.erase(ind);
                    one.erase(fone);
                    two.erase(ftwo);

                    zero.insert(fone);
                    one.insert(ftwo);
                    // two.insert(ind);

                    k+=2;
                    ans.push_back({fone,ind});
                    ans.push_back({ftwo,ind});
                }

            }

            if(!one.empty()){
                if(arr[ind]==1){
                    one.erase(ind);
                }

                else if(arr[ind]==0){
                    int fone = *one.begin();
                    swap(arr[ind],arr[fone]);

                    one.erase(fone);
                    // two.insert(ind);

                    zero.erase(ind);
                    zero.insert(fone);

                    k++;
                    ans.push_back({fone,ind});
                }
            }
            ind--;
        }
        cout<<k<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        }
        t--;
    }
    return 0;

} 