// Given a number N you need to reduce it to 1 by following operation
// 1. Reduce N --> N-1
// 2.Reduce N --> N/2
// 3.Reduce N --> N/3

// Find minimum number of steps to reduce it to 1

#include<iostream>
#include<climits>
#include<vector>
#define inf INT_MAX

using namespace std;

vector<int>dp;


int reduce(int n){
    if(n==1) return 0;
    if(dp[n-1]!=-1) return dp[n-1];
    int a=INT_MAX,b=INT_MAX;
    if(n%3==0){
        a=reduce(n/3)+1;
    }
    if(n%2==0){
        b=reduce(n/2)+1;
    }
    return dp[n-1]=min(a,min(b,reduce(n-1)+1));
}

int reduce_td(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    return 1+min(reduce_td(n-1),min((n%2==0)?reduce_td(n/2):inf,(n%3==0)?reduce_td(n/3):inf));
}

int bu(int n){
    dp.resize(n+5,-1);
    dp[1]=1;
    dp[2]=dp[3]=1;
    for(int i=4;i<=n;++i){
        dp[i]=1+min(dp[i-1],min((i%2==0)?dp[i/2]:inf,(i%3==0)?dp[i/3]:inf));
    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    // count=0;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<reduce_td(n)<<" "<<bu(n);
}