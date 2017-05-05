#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
	string str;
	cin>>str;
	int m;
	cin>>m;
	int array[str.size()];
	for(int i = 0 ; i <str.size() -1 ; i++){
		if(str[i]==str[i+1])
		array[i]=1;
		else
		array[i]=0;
	}
	int sumArray[str.size()];
	sumArray[0]=0;
	for(int i = 1 ; i<str.size() ; i++){
		sumArray[i]=sumArray[i-1]+array[i-1];
	}
	for(int i = 0 ; i< m ; i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		if(x==y)
		cout<<0<<endl;
		else if(x==0){
			cout<<sumArray[y]<<endl;
		}
		else
		cout<<sumArray[y]-sumArray[x]<<endl;
	}
}
