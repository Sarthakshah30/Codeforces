#include<iostream>
#include<cstring>

using namespace std;
#define inf -99999;

int main(){
	int n,array[3];
	cin>>n>>array[0]>>array[1]>>array[2];
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i = 1 ; i<=n ; i++){
		dp[i]=inf;
		for(int j = 0 ; j< 3 ; j++){
			if(i-array[j]>=0){
				dp[i]=max(dp[i],1+dp[i-array[j]]);
			}
		}
	}
	cout<<dp[n]<<endl;
}
