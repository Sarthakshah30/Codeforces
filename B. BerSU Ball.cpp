#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
	int m,n;
	cin>>m;
	int array[m];
	for(int i = 0 ; i< m ; i++)
	cin>>array[i];
	cin>>n;
	int array2[n];
	for(int i = 0 ; i< n ; i++)
	cin>>array2[i];
	
	int dp[m+1][n+1];
	for(int i = 0 ;i<=m ; i++){
		dp[i][n]=0;
	}
	for(int i = 0 ; i<=n ; i++){
		dp[m][i]=0;
	}
	sort(array,array+m);
	sort(array2,array2+n);
	
	for(int i = m-1 ; i>=0 ; i--){
		for(int j = n-1 ; j>=0 ; j--){
			dp[i][j]=0;
			if(abs(array[i]-array2[j])<=1){
				dp[i][j]=1+dp[i+1][j+1];
			}
			dp[i][j]=max(dp[i][j],dp[i+1][j]);
			dp[i][j]=max(dp[i][j],dp[i][j+1]);
		}
	}
	cout<<dp[0][0]<<endl;
}
