#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n,x,y=-1;
	int count[100004];
	memset(count,0,sizeof(count));
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>x;
		if(x>y)
		y=x;
		count[x]++;
	}
	long long int dp[100004];
	dp[0]=0;
	dp[1]=count[1];
	for(int i = 2 ; i<=y ; i++){
		dp[i]=dp[i-1];
		if(i>1)
		dp[i]=max(dp[i],dp[i-2]+(i*count[i]));
	}
	cout<<dp[y]<<endl;
}
