#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
	int row,col;
	cin>>row>>col;
	vector<string> matrix;
	for(int i = 0 ; i < row ; i++){
		string str;
		cin>>str;
		matrix.push_back(str);
	}
	int horizontal[row][col];
	int vertical[row][col];
	for(int i = 0 ; i  < row ; i++){
		for(int j = 0 ; j <col-1 ; j++){
			horizontal[i][j]=0;			
			if(matrix[i][j]=='.' && matrix[i][j+1]=='.')
			horizontal[i][j]=1;
			if(i!=0 && j!=0){
				horizontal[i][j]+=horizontal[i-1][j]+horizontal[i][j-1]-horizontal[i-1][j-1];
			}
			else if(i==0 && j!=0){
				horizontal[i][j]+=horizontal[i][j-1];
			}
			else if(i!=0 && j==0){
				horizontal[i][j]+=horizontal[i-1][j];
			}
		}
	}
	
	for(int i = 0 ;i<row-1 ; i++){
		for(int j = 0 ; j<col ; j++){
			vertical[i][j]=0;
			if(matrix[i][j]=='.' && matrix[i+1][j]=='.')
			vertical[i][j]=1;
			if(i!=0 && j!=0){
				vertical[i][j]+=vertical[i-1][j]+vertical[i][j-1]-vertical[i-1][j-1];				
			}
			else if(i==0 && j!=0){
				vertical[i][j]+=vertical[i][j-1];				
			}
			else if(i!=0 && j==0){
				vertical[i][j]+=vertical[i-1][j];
			}		
		}
	}
	int dp[502][502];
	dp[0][0]=0;
	for(int i = 0 ; i<row ; i++){
		for(int j = 0 ; j<col ; j++){
			if(i!=0 && j!=0){
				dp[i][j]=horizontal[i][j-1]+vertical[i-1][j];
			}
			if(i==0 && j!=0){
				dp[i][j]=horizontal[i][j-1];
			}
			if(i!=0 && j==0){
				dp[i][j]=vertical[i-1][j];				
			}
			cout<<dp[i][j]<<" ";		
		}
		cout<<endl;
	}
	int query;
	cin>>query;
	for(int i = 0 ; i<query ; i++){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		r1--;
		c1--;
		r2--;
		c2--;
		int ans = dp[r2][c2];
		if(r1==0 && c1==0){
			cout<<ans<<endl;
			continue;
		}
		else if(r1>0 && c1>0){
			cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
			ans=ans-dp[r1][c2]-dp[r2][c1]+dp[r1][c1];
			cout<<ans<<endl;
			continue;			
		}
		else if(r1==0){
			ans=ans-dp[r2][c1];
			cout<<ans<<endl;
			continue;
		}
		else if(c1==0){
			ans=ans-dp[r1][c2];
			cout<<ans<<endl;
			continue;			
		}
	}
}
