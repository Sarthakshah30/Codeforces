#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
	string str;
	cin>>str;
	for(int i = 0 ; i< str.size() ; i++){
		if(str[i]=='0' || str[i]=='8'){
			cout<<"YES"<<endl;
			if(str[i]=='0')
			cout<<"0"<<endl;
			else
			cout<<"8"<<endl;
			return 0;
		}
	}
	if(str.size()<=2){
		if(str.size()==1){
			cout<<"NO"<<endl;
			return 0;
		}
		int temp = str[0]-'0';
		temp*=10;
		temp+=str[1]-'0';
		if(temp%8==0){
			cout<<"YES"<<endl;
			cout<<temp<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	vector<int> vec(str.size()-2,0);
	vec.push_back(1);
	vec.push_back(1);
	do{
		int i,temp;
		for(i =0 ; i<vec.size() ; i++){
			if(vec[i]==1)
			break;
		}
		temp=(str[i]-'0')*10;
		i++;
		for(; i<vec.size() ;i++){
			if(vec[i]==1)
			break;
		}
		temp+=str[i]-'0';
		if(temp%8==0){
			cout<<"YES"<<endl;
			cout<<temp<<endl;
			return 0;
		}
	}
	while(next_permutation(vec.begin(),vec.end()));
	vec.clear();
	vec.assign(str.size()-3,0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	do{
		int i,temp;
		for(i =0 ; i<vec.size() ; i++){
			if(vec[i]==1)
			break;
		}
		temp=(str[i]-'0')*10;
		i++;
		for(; i<vec.size() ;i++){
			if(vec[i]==1)
			break;
		}
		temp+=str[i]-'0';
		temp*=10;
		i++;
		for(; i<vec.size() ;i++){
			if(vec[i]==1)
			break;
		}
		temp+=str[i]-'0';		
		if(temp%8==0){
			cout<<"YES"<<endl;
			cout<<temp<<endl;
			return 0;
		}		
	}
	while(next_permutation(vec.begin(),vec.end()));
	cout<<"NO"<<endl;
}
