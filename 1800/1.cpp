#include <iostream> 
#include <queue>
#include <vector>
#include<unordered_map>
#include<cmath> 
#include <algorithm>
#include<climits>
#include<set>
#include<string>

using namespace std; 

bool inside(int i, int j, int r, int c){
    if(i>=0 && i<r && j>=0 && j<c){
        return true;
    }
    return false;
}

pair<int,int> dirchange(int i, int j, int previ, int prevj,vector<vector<char>> &arr){

    int ni ,nj;
    
    if(arr[i][j]=='.'){
        if(previ==i) {
            ni = i;
            nj = j + j-prevj;
        }
        else{
            nj = j;
            ni = i+i-previ;
        }
    }
    else if(arr[i][j]=='/'){
        if(previ==i) {
            nj = j;
            ni = i - j+prevj;
        }
        else{
            ni = i;
            nj = j-i+previ;
        }
    }
    else{
        if(previ==i) {
            nj = j;
            ni = i + j-prevj;
        }
        else{
            ni = i;
            nj = j+i-previ;
        }
    }
    return {ni,nj};
}

int dfs(int i, int j, int previ, int prevj, vector<vector<char>> &arr , int r, int c,vector<vector<int>> &vis){

    if(!inside(i,j,r,c)){
        return 0;
    }
    int cnt = 0;
    
    if(arr[i][j]!='.') {
        if(vis[i][j]==0) cnt++;
    }
    vis[i][j] = 1;

    int ni,nj;

    pair<int,int> ncordinates = dirchange(i,j,previ,prevj,arr);
    ni = ncordinates.first;
    nj = ncordinates.second;

    cnt+=dfs(ni,nj,i,j,arr,r,c,vis);

    return cnt;

}


// Driver Code 
int main() 
{ 
    // int t;
    // cin>>t;


    // while(t>0){
        
        int r,c;
        cin>>r>>c;

        vector<vector<char>> arr(r,vector<char>(c,'.'));

        int num = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>arr[i][j];

                if(arr[i][j]!='.') num++;
            }
        }

        int k = 0;
        vector<string> ans;

        for(int i=0;i<r;i++){
            vector<vector<int>> vis(r,vector<int>(c,0));
            int cnt = dfs(i,0,i,-1,arr,r,c,vis);

            if(cnt==num) {
                k++;
                string s = "W" + to_string(i+1);
                ans.push_back(s);
            }
            // Assuming r and c are the number of rows and columns
            vis.assign(r, vector<int>(c, 0));


            cnt = dfs(i,c-1,i,c,arr,r,c,vis);

            if(cnt==num) {
                k++;
                string s = "E" + to_string(i+1);
                ans.push_back(s);
            }
        }

        for(int i=0;i<c;i++){
            vector<vector<int>> vis(r,vector<int>(c,0));
            int cnt = dfs(0,i,-1,i,arr,r,c,vis);

            if(cnt==num) {
                k++;
                string s = "N" + to_string(i+1);
                ans.push_back(s);
            }
            // Assuming r and c are the number of rows and columns
            vis.assign(r, vector<int>(c, 0));


            cnt = dfs(r-1,i,r,i,arr,r,c,vis);

            if(cnt==num) {
                k++;
                string s = "S" + to_string(i+1);
                ans.push_back(s);
            }
        }

        cout<<k<<endl;

        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<endl;


    //     t--;
    // }
    return 0;

} 