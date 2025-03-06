#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int dp[105][105][3];

int Adj(int n,int k,int prev){
    if(n==0) return 0;
    if(n==1 && k==0) return 1;
    if(n==1 && k!=0) return 0;

    if(dp[n][k][prev]!=-1) return dp[n][k][prev];

    if(prev==1){
        return dp[n][k][1]=Adj(n-1,k-1,1)+Adj(n-1,k,0);
    }
    else{
        return dp[n][k][0]=Adj(n-1,k,1)+Adj(n-1,k,0);
    }
}

int main(){
    int p;
    cin>>p;
    int n,k;
    for(int i=1;i<=p;++i){
        int idx;
        cin>>idx>>n>>k;
        memset(dp,-1,sizeof dp);
        int ans=Adj(n,k,0)+Adj(n,k,1);
        cout<<idx<<" "<<ans<<"\n";
    }
    return 0;
    
}