#include<bits/stdc++.h>
using namespace std;
long long a[65][65];
long long s=1<<30;
int main(){
	for(int i=0;i<=60;i++){
		a[i][0]=1;
		for(int j=i;j<=i;j++){
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	cout<<s*s-a[58][29]+a[58][27]-2*a[59][30];
}
