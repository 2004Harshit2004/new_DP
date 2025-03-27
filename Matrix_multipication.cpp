#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<int>> dp;

// Top-Down solution
int f(vector<int>&v, int i, int j){
    if(i==j or i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;++k){
        ans=min(ans,(f(v,i,k)+f(v,k,j)+v[i]*v[k]*v[j]));
    }
    return dp[i][j]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }

    dp.clear();
    dp.resize(n,vector<int>(n,0));

    // Bottom Up solution
    for(int len=3;len<=n;++len){
        for(int i=0;i<n-len+1;++i){
            int j=i+len-1;
            int ans=INT_MAX;
            for(int k=i+1;k<j;++k){
                ans=min(ans,dp[i][k]+dp[k][j]+v[i]*v[k]*v[j]);
            }
            dp[i][j]=ans;
        }
    }


    cout<<dp[0][n-1];

    // cout<<f(v,0,n-1);
    return 0;

}