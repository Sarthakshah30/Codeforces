#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

vector<int> vec[7];

void precalculate(int n){
	int model = pow(10,n-1);
	for(int i = 1; i<n ; i++){
		for(int j = 0 ; j<vec[i].size() ; j++){
			vec[n].push_back(model+vec[i][j]);
		}
	}
}

int getDigits(int n){
	int count=0;
	while(n>0){
		n=n/10;
		count++;
	}
	return count;
}

int dp[1000001];

int calculate(int n,int digits){
	if(n==0)
	return 0;
	int &ans = dp[n];
	if(ans!=-1)
	return ans;
	ans=999999;
	for(int i = 1 ; i<=digits ; i++){
		for(int j =0 ; j<vec[i].size() ; j++){
			int temp = vec[i][j];
			if(vec[i][j]<=n){
				ans=min(ans,calculate(n-temp,digits)+1);
			}
		}
	}
	return ans;
}

int main(){
	vec[1].push_back(1);
	vec[1].push_back(0);
	for(int i = 2 ; i<=6 ; i++){
		precalculate(i);
	}
	vec[1].erase(vec[1].begin()+1);
	memset(dp,-1,sizeof(dp));
	int n,digits;
	cin>>n;
	digits=getDigits(n);
	cout<<calculate(n,digits)<<endl;
}




