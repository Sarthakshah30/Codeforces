#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> divisor[n+1];
	for(int i =1; i <=n ; i++){
		for(int j = i ; j<=n ; j+=i){
			divisor[j].push_back(i);
		}
	}
	long dp[k][n+1];
	for(int i = k-1 ; i>=0 ; i--){
		for(int j = 1 ; j<=n ; j++){
			if(i==k-1)
			dp[i][j]=1;
			else{
				dp[i][j]=0;
				for(int p = 0 ; p<divisor[j].size() ; p++){
					int y = divisor[j][p];
					dp[i][j]=(dp[i][j]+dp[i+1][y])%1000000007;
				}

			}
		}
	}
	long sum=0;
	for(int i = 1 ; i<=n ; i++)
	sum=(sum+dp[0][i])%1000000007;
	cout<<(int)sum<<endl;
}
