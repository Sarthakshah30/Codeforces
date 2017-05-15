#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	if(m>2*(n+1) || m<n-1)
	cout<<-1<<endl;
	else{
		string str="";
		if(n>=m){
			while(n!=0 || m!=0){
				if(n>0)
				{
					str+="0";
					n--;
				}
				if(m>0){
					str+="1";
					m--;
				}
			}
		}
		else{
			while(n!=0 || m!=0){
				if(m>0){
					if(m==n || m==n+1){
						str+="1";
						m--;
					}
					else{
						str+="11";
						m-=2;
					}
				}
				if(n>0){
					str+="0";
					n--;
				}
			}
		}
		cout<<str<<endl;
	}
}
