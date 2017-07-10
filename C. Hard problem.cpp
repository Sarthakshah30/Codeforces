#include<iostream>
#include<cstring>
#include<algorithm>

#define INF 10000000000000000
using namespace std;

int main(){
	int n;
	cin>>n;
	int cost[n+1];
	string s[n+1],r[n+1];
	long long int dp[n+1][2];
	for(int i = 1 ; i <= n ; i++){
		cin>>cost[i];
		dp[i][1]=dp[i][0]=INF;
	}
	for(int i = 1 ; i <= n ; i++){
		cin>>s[i];
		r[i]=s[i];
		reverse(r[i].begin(),r[i].end());
	}
	dp[1][0]=0;
	dp[1][1]=cost[0];
	for(int i = 2 ; i<=n ; i++){
		if(s[i]>=s[i-1])
		dp[i][0]=dp[i-1][0];
		if(s[i]>=r[i-1])
		dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(r[i]>=s[i-1])
		dp[i][1]=dp[i-1][0]+cost[i];
		if(r[i]>=r[i-1])
		dp[i][1]=min(dp[i][1],dp[i-1][1]+cost[i]);		
	}
	dp[n][0]=min(dp[n][1],dp[n][0]);
	cout<<(dp[n][0] >= INF ? -1 : dp[n][0])<<endl;
}
