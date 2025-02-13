#include<iostream>
#include<vector>
using namespace std;

//  Function to return Nth Fibbonaci

vector<int> dp;


int fibbo_reccursive(int n){
    if(n==0 || n==1) return n;
    return fibbo_reccursive(n-1)+fibbo_reccursive(n-2);
}


int top_down_dp(int n){
    if(n==1 || n==0) return n;
    if(dp[n]!=-1) return dp[n]; 
    return dp[n]=top_down_dp(n-1)+top_down_dp(n-2);
}

int bottom_up_dp(int n){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"enter the value of n";
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);

    cout<<top_down_dp(n);
}