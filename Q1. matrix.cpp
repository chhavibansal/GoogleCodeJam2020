#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int count = 1;
    while(t--){
        int n;
        cin >> n;
        int sum = 0 , num,row_rep = 0 , col_rep = 0;
        
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> dp[i][j];
                if(i == j ){
                    sum+= dp[i][j];
                }
                
            }
        }
        for(auto row : dp){
            map<int,int>mp;
            for(int x : row ){
                mp[x]+=1 ;
                if(mp[x] > 1){
                    row_rep+=1;
                    break;
                } 
            }
        }
        for(int i = 0 ; i < n ; i++){
            map<int,int> mp;
            for(int j = 0 ; j < n ; j++){
                mp[dp[j][i]]+=1;
                if(mp[dp[j][i]] > 1){
                    col_rep+=1;
                    break;
                }
            }
        }
        cout << "Case #"<<count<<": "<<sum<<" "<<row_rep<<" "<<col_rep<<"\n";
        count+=1;
    }
}