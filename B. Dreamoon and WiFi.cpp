#include<iostream>
#include<cstring>

using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int destination=0,dist=0,moves=0;
	for(int i = 0; i<s1.size() ; i++){
		destination+=(s1[i]=='+' ? 1 : -1);
	}
	for(int i = 0 ; i<s2.size() ; i++){
		if(s2[i]=='?')
		moves++;
		else
		dist+=(s2[i]=='+' ? 1 : -1);
	}
	
	dist= destination-dist;
	double res=0;
	if((dist+moves)%2!=0 || moves < abs(dist))
	res=0;
	else{
		int r = (abs(dist)+moves)/2;
		int c=1;
        for(int i=0;i<r;i++)
            c *= moves-i ;
        for(int i=2;i<=r;i++)
            c /= i ;
		res = (double) c / (1<<moves);
	}
	printf("%.12f\n", res) ;
}
