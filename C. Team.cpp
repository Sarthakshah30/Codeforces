#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int mm=ceil(m/2);
	if(abs(mm-n)>1){
		cout<<-1<<endl;
	}
	else{
		string str="";
		if(mm>=n){
			while(m!=0 || n!=0){
				if(m>0){
					if(m>=2){
						m-=2;
						str+="11";
					}
					else{
						m-=1;
						str+="1";
					}
				}
				if(n>0){
					n-=1;
					str+="0";
				}
			}
		}
		else{
			while(m!=0 || n!=0){
				if(n>0){
					n-=1;
					str+="0";
				}
				if(m>0){
					if(m>=2){
						m-=2;
						str+="11";
					}
					else{
						m-=1;
						str+="1";
					}
				}								
			}
		}
		cout<<str<<endl;
	}
}
