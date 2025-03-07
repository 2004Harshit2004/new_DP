#include<iostream>
#include<vector>
#include <climits>
#define ll long long


using namespace std;

vector<vector<int>> dp;

ll f(vector<int> &a, vector<int> &c,int i,int x){
    if(i==a.size()) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    if(x==0){
        return dp[i][x]=a[i]+f(a,c,i+1,x+1);
    }
    if(x==a.size()-i){
        return dp[i][x]=c[i]+f(a,c,i+1,x-1);
    }
    else{
        // dp[i+1][x+1]=a[i]+f(a,c,i+1,x+1);
        // dp[i+1][x-1]=c[i]+f(a,c,i+1,x-1);
        return dp[i][x]=min(a[i]+f(a,c,i+1,x+1),c[i]+f(a,c,i+1,x-1));
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> A;
    vector<int> C;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x;
        C.push_back(x);
        cin>>y;
        A.push_back(y);
    }

    dp.clear();
    dp.resize(n+5,vector<int>(n+5,-1));

    cout<<f(A,C,0,0);
    return 0;
}