#include<iostream>
#include<vector>
#define ll long long

using namespace std;

vector<vector<ll>> dp;

ll f(vector<ll> &w,vector<ll> &v, ll W,int i){
    if(i==w.size()) return 0;
    if(dp[i][W]!=-1) return dp[i][W];
    if(w[i]>W) return dp[i][W]=f(w,v,W,i+1);
    ll v1=v[i]+f(w,v,W-w[i],i+1);
    ll v2=f(w,v,W,i+1);
    return dp[i][W]=max(v1,v2);
}

// ll fbu(vector<ll> &w,vector<ll> &v,ll W){
    
//     for(int i=1;i<=v.size();++i){
//         for(int j=1;j<=w.size();++j){
//             dp[i][w]=max(dp[i-1][w])
//         }
//     }
// }

int main(){
    int n;
    ll W;
    cin>>n;
    cin>>W;
    vector<ll> w,v;   
    for(int i=0;i<n;++i){
        ll x,y;
        cin>>x;
        cin>>y;
        w.push_back(x);
        v.push_back(y);
    }

    dp.clear();
    dp.resize(n+5,vector<ll>(W+1,-1));

    cout<<f(w,v,W,0);
    return 0;

}