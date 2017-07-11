#include<iostream>
#include<cstring>

using namespace std;
long long int sum[5002];
int n,m,k;
long long int dp[5002][5002];
long long int calculate(int index,int k);
#define INF -100000000000000

int main(){
	cin>>n>>m>>k;
	sum[0]=0;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin>>x;
		sum[i]+=sum[i-1]+x;
	}
	memset(dp,-1,sizeof(dp));
	cout<<calculate(1,k)<<endl;
}

long long int calculate(int index,int k){
	if(k==0 || index==n+1)
	return 0;
	long long int &ans = dp[index][k];
	if(ans!=-1)
	return ans;
	ans=INF;
	ans=calculate(index+1,k);
	if(m-1+index<=n)
	ans=max(ans,calculate(index+m,k-1)+sum[m-1+index]-sum[index-1]);
	return ans;
}
