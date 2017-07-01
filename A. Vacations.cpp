#include<iostream>
#include<cstring>

using namespace std;
int n;
int array[150];
int dp[120][4];

int calculate(int day,int last){
	if(day==n)
	return 0;
	int & ans = dp[day][last];
	if(ans!=-1)
	return ans;
	ans=9999999;
	if(last!=1 && (array[day]==1 || array[day]==3))
	ans=min(ans,calculate(day+1,1));
	if(last!=2 && (array[day]==2 || array[day] ==3))
	ans=min(ans,calculate(day+1,2));
	ans=min(ans,1+calculate(day+1,0));
	return ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i = 0 ; i< n ; i++)
	cin>>array[i];
	cout<<calculate(0,0)<<endl;
}


