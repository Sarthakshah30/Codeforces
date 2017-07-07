#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;


int main(){
	int n,m;
	cin>>n;
	vector<long long int> sortedSum(n+1,0);
	vector<long long int> initialSum(n+1,0);
	sortedSum[0]=0;
	initialSum[0]=0;
	for(int i = 1 ; i<= n  ; i++){
		cin>>sortedSum[i];
		initialSum[i]=initialSum[i-1]+sortedSum[i];
	}
	sort(sortedSum.begin(),sortedSum.end());
	for(int i = 1 ; i<= n ; i++){
		sortedSum[i]=sortedSum[i-1]+sortedSum[i];
	}
	cin>>m;
	for(int i = 0 ; i< m ; i++){
		int type,x,y;
		cin>>type>>x>>y;
		if(type==1){
			cout<<initialSum[y]-initialSum[x-1]<<endl;
		}
		else{
			cout<<sortedSum[y]-sortedSum[x-1]<<endl;
		}
	}
}
