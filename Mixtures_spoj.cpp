#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int dp[105][105];

int mul(vector<int> & v,int i,int j){
    int sum=0;
    for(int x=i;x<=j;++x){
        sum+=v[x];
    }
    return sum%100;
}

int f(vector<int> & v,int i,int j){
    if(i==j) return 0;
    int ans=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;++k){
        ans=min(ans,f(v,i,k)+f(v,k+1,j)+mul(v,i,k)*mul(v,k+1,j));
    }
    return dp[i][j]=ans;
}

int main(){
    int n;
    vector<int> ans;
    vector<int> color(105,0);
    while(cin>>n){
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            color[i]=x;
        }
        memset(dp,-1,sizeof dp);
        int hg=f(color,0,n-1);
        ans.push_back(hg);
        color.clear();
    }

    
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<"\n";
    }

    return 0;

}