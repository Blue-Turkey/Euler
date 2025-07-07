#include<bits/stdc++.h>
using namespace std;
long long p[5005][5005];
long long big=1234567891;
long long n2=(big+1)/2;
long long sum=0;
int main(){
	for(int i=0;i<=5000;i++){
		p[0][i]=1;
	}
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=5000;j++){
			if(i<j) p[i][j]=p[i][i];
			else p[i][j]=(p[i-j][j]+p[i][j-1])%big;
		}
	}
	for(int i=0;i<=5000;i++){
		for(int j=0;j<=5000-i;j++){
			sum=(sum+p[i][i]*p[j][j])%big;
		}
	}
	for(int i=0;i<=2500;i++){
		for(int j=0;j<=5000-2*i;j++){
			for(int k=5000-2*i-j;k>=0;k=k-1){
				sum=(sum-p[i][j]*p[i][k])%big;
			}
		}
	}
	sum=(sum*n2)%big;
	for(int i=0;i<2500;i++){
		for(int j=0;j<=4998-2*i;j++){
			for(int k=4998-2*i-j;k>=0;k=k-2){
				sum=(sum-p[i+1][j]*p[i][k])%big;
			}
		}
	}
	sum=(sum+big)%big;
	cout<<sum;
}
