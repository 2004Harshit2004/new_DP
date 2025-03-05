#include <iostream>
#include<vector>
using namespace std;

vector<vector<vector<int>>> dp;

int Klcs(vector<int>& n,vector<int>& m,int i,int j,int k){
	int n_size=n.size();
	int m_size=m.size();
	if(i>=n_size) return 0;
	if(j>=m_size) return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(n[i]==m[j]){
		dp[i][j][k]=1+Klcs(n,m,i+1,j+1,k);
		return dp[i][j][k];
	}
	else{// optimize it function is calculating many time in your code 
		if(k<=0){
			dp[i][j][k]=max(Klcs(n,m,i+1,j,k),Klcs(n,m,i,j+1,k));
			return dp[i][j][k];
		}
		else{
			dp[i][j][k]=max(1+Klcs(n,m,i+1,j+1,k-1),max(Klcs(n,m,i+1,j,k),Klcs(n,m,i,j+1,k)));
			return dp[i][j][k];
		}
	}
}


int main() {
	int n,m;
	cin >> n >> m;
	int k;
	cin>>k;  
	vector<int> n1;
	vector<int> n2;
	for(int i=0;i<n;++i){
		int a;
		cin>> a;
		n1.push_back(a);
	}
	for(int i=0;i<m;++i){
		int a;
		cin>> a;
		n2.push_back(a);
	}
	
	dp.clear();
	dp.resize(2005,vector<vector<int>>(2005,vector<int>(8,-1)));
	cout << "Input number is " << Klcs(n1,n2,0,0,k) << endl;	// Writing output to STDOUT
	return 0;
}