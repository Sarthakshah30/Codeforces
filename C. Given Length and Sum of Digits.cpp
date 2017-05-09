#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
	int length,sum,sum2;
	cin>>length>>sum;
	sum2=sum;
	string digits[]={"0","1","2","3","4","5","6","7","8","9"};
	if(length>1 && sum==0){
		cout<<-1<<" "<<-1<<endl;
	}
	else if(sum==0 && length==1){
		cout<<0<<" "<<0<<endl;
	}
	else{
		bool possible=true;
		string first="";
		for(int i = 1 ; i<=length ;i++){
			if(i==1){
				int j;
				for(j=1 ; j<=9 ; j++){
					if( sum-j <= 9*(length-i) ){
						first+=digits[j];
						sum-=j;
						break;
					}
				}
				if(j==10)
				possible=false;
			}
			else{
				int j;
				for(j=0 ; j<=9 ;j++){
					if(sum-j <= 9*(length-i) ){
						first+=digits[j];
						sum-=j;
						break;
					}
				}
				if(j==10)
				possible=false;
			}
		}
		if(sum!=0)
		possible=false;
		string second="";
		for(int i=1 ; i<=length ;i++){
			if(i==1){
				int j;
				for(j=9 ; j>=1 ; j--){
					if(sum2-j <= 9*(length-i) && j<=sum2 ){
						second+=digits[j];
						sum2-=j;
						break;
					}
				}
				if(j==0)
				possible=false;
			}
			else{
				int j;
				for(j=9 ; j>=0 ; j--){
					if(sum2-j <= 9*(length-i) && j<=sum2 ){
						second+=digits[j];
						sum2-=j;
						break;
					}
				}
				if(j==-1)
				possible=false;
			}
		}
		if(sum2!=0)
		possible=false;
		if(possible)
		cout<<first<<" "<<second<<endl;
		else
		cout<<-1<<" "<<-1<<endl;
	}
}
