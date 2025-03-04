#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    vector<vector<int>> dp(n+5,vector<int> (3,-1));
    // input a --> 0 index, b--> 1 index and c--> 2 index
    dp[1][0]=a;
    dp[1][1]=b;
    dp[1][2]=c;
    for(int i=2;i<=n;++i){
        cin>>a>>b>>c;
        dp[i][0]=a+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
}