#include<iostream>
#include<climits>
#include<vector>

using namespace std;

vector<int> dp;

// int remove_digits(int n){
//     if(n==0) return 0;
//     if(n<=9) return 1;
//     if(dp[n-1]!=-1) return dp[n-1];
//     int x=n;
//     int ans=INT_MAX;
//     while(x){
//         while(x%10==0) x/=10;
//         ans=min(ans,remove_digits(n-x%10));
//         x/=10;
//     }
//     return dp[n-1]=ans+1;
// }

vector<int> get_digits(int n){
    vector<int>hg;
    while(n){
        if(n%10!=0){
            hg.push_back(n%10);
        } 
        n/=10;
    }
    return hg;
}

int remove_digits_bu(int n){
    for(int i=0;i<=n;++i){
        if(i<=9){
            dp[i]=1;
            continue;
        }
        vector<int> hg=get_digits(i);
        dp[i]=INT_MAX;
        for(int j=0;j<hg.size();++j){
            dp[i]=min(dp[i],1+dp[i-hg[j]]);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<remove_digits_bu(n);
    return 0;
}