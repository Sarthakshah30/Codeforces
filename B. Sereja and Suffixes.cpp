#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int count[100001];
	memset(count,0,sizeof(count));
	int n,m,q,distinct=1;
	cin>>n>>m;
	int array[n];
	for(int i = 0 ; i < n ;i++)
	cin>>array[i];
	count[array[n-1]]=1;
	array[n-1]=1;
	for(int i = n-2 ; i>=0 ; i--){
		if(count[array[i]]==0){
			distinct++;
			count[array[i]]++;
			array[i]=distinct;
		}
		else{
			count[array[i]]++;
			array[i]=distinct;
		}
	}
	for(int i = 0 ; i< m ; i++){
		cin>>q;
		cout<<array[q-1]<<endl;
	}
}
