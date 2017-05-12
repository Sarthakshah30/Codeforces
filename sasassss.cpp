#include<iostream>
#include<cstring>
using namespace std;

int a[1000010];
long long cnt[1000010];

int main(){
	int n;
	cin>>n;
	long long int sum=0;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%3!=0){
		cout<<0<<endl;
	}
	else{
		sum/=3;
		long long s=0;
		for(int i = n-1 ; i>=0 ; i--){
			s+=a[i];
			if(s==sum)
			cnt[i]=1;
		}
		for(int i = n-2 ; i>=0 ; i--)
		cnt[i]+=cnt[i+1];
		
		long long ans=0;
		s=0;
		for(int i = 0 ; i+2<n ; i++){
			s+=a[i];
			if(s==sum){
				ans+=cnt[i+2];
			}
		}
		cout<<ans<<endl;
	}
}
