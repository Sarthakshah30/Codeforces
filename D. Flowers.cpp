#include<cstring>
#include<iostream>
#define MOD 1000000007

using namespace std;
int dp[100002];

int main(){
	memset(dp,-1,sizeof(dp));
	dp[0]=1;
	int test,k;
	cin>>test>>k;
	for(int i = 1 ; i<=100000 ; i++){
		long long int ans = 0;
		ans = dp[i-1];
		if(i-k>=0){
			ans = (ans+dp[i-k])%MOD;
		}
		dp[i]=(int)ans;
	}
	dp[0]=0;
	for(int i = 1 ; i<=100000 ; i++){
		long long int res = (dp[i]+dp[i-1])%MOD;
		dp[i]=(int)res;
	}
	while(test-->0){
		int a,b;
		cin>>a>>b;
		cout<<(dp[b]+MOD-dp[a-1])%MOD<<endl;
	}
}
