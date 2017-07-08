#include<iostream>
#include<cstring>
#define MOD 1000000007;

using namespace std;


int n;
int dp[10000001][4];

int calculate(int step,int curr){
	if(step==n && curr==3)
	return 1;
	if(step==n)
	return 0;
	int & ans = dp[step][curr];
	if(ans!=-1)
	return ans;
	long long int temp=0;
	for(int i = 0 ; i<4 ; i++){
		if(curr==i)
		continue;
		temp+=(calculate(step+1,i))%MOD;
	}
	ans=(int)temp;
	return ans;
}

int main(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<calculate(0,3)<<endl;
}

