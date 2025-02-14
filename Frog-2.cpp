// AtCoder Frog-2

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include<climits>

using namespace std;

vector<int> h;
int k;
vector<int> dp;
vector<int> dp_bu;


int score(int i){
    if(i==h.size()-1) return 0;
    if(i>=h.size()) return INT_MAX;
    int sc=INT_MAX,temp=0;
    for(int j=1;j<=k && i+j<=h.size()-1;++j){
        temp=abs(h[i]-h[i+j])+score(i+j);
        sc=min(sc,temp);
    }
    return sc;
}


int score_using_dp(int i){
    if(i==h.size()-1) return 0;
    if(i>=h.size()) return INT_MAX;
    if(dp[i]!=-1) return dp[i];
    int sc=INT_MAX;
    int temp;
    for(int j=1;j<=k;++j){
        if(i+j>=h.size()) break;
        temp=abs(h[i]-h[i+j])+score_using_dp(i+j);
        sc=min(temp,sc);
        
    }
    return dp[i]=sc;
}

int bottom_up_dp(int i){
    int n=h.size();
    dp_bu[n-1]=0;
    for(int j=n-2;j>=0;--j){
        int sc=INT_MAX;
        for(int p=1;p<=k;++p){
            if(j+p>=n) break;
            sc=min(sc,abs(h[j]-h[j+p])+dp_bu[j+p]);
        }
        dp_bu[j]=sc;
    }
    return dp_bu[i];
}


int main(){
    int n;
    cin>>n;
    cin>>k;
    h.clear();
    h.resize(n,-1);
    // dp.clear();
    // dp.resize(n,-1);
    for(int i=0;i<n;++i){
        cin>>h[i];
    }
    dp_bu.clear();
    dp_bu.resize(n,-1);

    cout<<bottom_up_dp(0);
}