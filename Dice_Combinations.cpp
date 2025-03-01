#include<iostream>
#include<vector>
#define mod 1000000007

using namespace std;

vector<int> dp;

// int dice(int n){
//     if(n==0) return 1;
//     if(dp[n]!=-1) return dp[n];
//     int ans=0;
//     for(int i=1;i<=6;++i){
//         if(n-i>=0){
//             ans=((ans%mod)+(dice(n-i)%mod))% mod;
//             // ans+=dice(n-i);
//         }
//         else break;
//     }
//     return dp[n]=ans % mod;
// }

int dice_bu(int n){
    dp[0]=1;
    for(int i=1;i<=n;++i){
        dp[i]=0;
        for(int j=1;j<=6;++j){
            if(i-j>=0) dp[i]=((dp[i] % mod)+(dp[i-j]%mod))%mod;
            else break;
        }
    }
    return dp[n]% mod;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<dice_bu(n);
}