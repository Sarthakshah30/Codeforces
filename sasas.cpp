#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int array[m];
	for(int i = 0 ; i<m ; i++)
	cin>>array[i];
	sort(array,array+m);
	int max=999999;
	for(int i = 0 ; i<=m-n ; i++){
		if(max > (array[i+n-1]-array[i]))
		max = array[i+n-1]-array[i];
	}
	cout<<max<<endl;
}
