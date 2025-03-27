#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> L(1000005);
    vector<int> R(1000005);
    for(int i=0;i<m;++i){
        int l,r;
        cin>>l>>r;
        L[l]++;
        R[r]++;
    }

    int Q;
    cin>>Q;
    vector<int> vq;
    for(int i=0;i<Q;++i){
        int q;
        cin>>q;
        vq.push_back(q);
    }

    vector<int> v(1000005,0);
    v[1]=L[1];
    for(int i=2;i<n+1;++i){
        v[i]=L[i]+v[i-1]-R[i-1];
    }

    vector<int> c(1000005,0);
    for(int i=1;i<n+1;++i){
        c[v[i]]++;
    }

    for(int i=n+1;i>0;--i){
        c[i]=c[i]+c[i+1];
    }

    for(int i=0;i<vq.size();++i){
        cout<<c[vq[i]]<<"\n";
    }

}