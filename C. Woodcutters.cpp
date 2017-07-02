#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
 	int array[n][2];
 	for(int i = 0 ; i< n ; i++){
 		cin>>array[i][0]>>array[i][1];
	}
	int ans = 1;
	int lastpoint=array[0][0];
	for(int i =1 ;i< n ; i++){
		if(i==n-1){
			ans++;
			continue;
		}
		if(array[i][0]-array[i][1]>lastpoint){
			ans++;
			lastpoint=array[i][0];
		}
		else{
			if(array[i][0]+array[i][1]<array[i+1][0]){
				ans++;
				lastpoint=array[i][0]+array[i][1];
			}
			else{
				lastpoint=array[i][0];
			}
		}
	} 
	cout<<ans<<endl;
}
