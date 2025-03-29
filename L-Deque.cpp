#include<iostream>
#include<vector>
#include<cstring>
#define ll long long

using namespace std;

ll dp[3005][3005][3];

ll f(vector<int>& seq,int i,int j,int c){
    // if(i>j) return 0;
    if(dp[i][j][c]!=-1) return dp[i][j][c];
    if(c==0){
        if(i==j) return seq[i];
        // cout<<seq[i];
        return dp[i][j][c]=max(seq[i]+f(seq,i+1,j,1),seq[j]+f(seq,i,j-1,1));
    }
    else{
        if(i==j) return (-seq[i]);
        return dp[i][j][c]=min((-seq[i])+f(seq,i+1,j,0),(-seq[j])+f(seq,i,j-1,0));
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> seq;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        seq.push_back(x);
    }
    // cout<<seq[n-1];
    memset(dp,-1,sizeof dp);
    cout<<f(seq,0,n-1,0);

}