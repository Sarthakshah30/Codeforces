#include<iostream>
#include<cstring>

using namespace std;
int dp[300][300];
int calculate(int a,int b);

int main(){
	int a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	cout<<calculate(a,b)<<endl;
}

int calculate(int a,int b){
	if(a<=0 || b<=0)
	return 0;
	int &ans = dp[a][b];
	if(ans!=-1)
	return ans;
	ans=0;
	if(a>1)
	ans=1+calculate(a-2,b+1);
	if(b>1)
	ans=max(ans,1+calculate(a+1,b-2));
	if(ans==0)
	return 0;
	return ans;
}


