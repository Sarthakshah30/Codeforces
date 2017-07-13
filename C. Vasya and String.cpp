#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n,k,i,j,ans=1,aCount=0,bCount=0;
	cin>>n>>k;
	string str;
	cin>>str;
	i=0;
	for(int j = 0; j<n ; j++){
		if(str[j]=='a')
			aCount++;
		else
		bCount++;
		if(min(aCount,bCount)>k){
			if(str[i]=='a')
			aCount--;
			else
			bCount--;
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
}
