#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long b[10005];
long long s[10005];
long long c[10005];
long long ans[10005];
long long m=900497239;
long long m2=(m+1)/2;
long long tt;
int main(){
	c[0]=1;
	c[1]=2;
	a[1]=1;
	b[1]=3;
	for(int i=1;i<10000;i++){
		a[i+1]=(a[i]*4)%m;
		b[i+1]=(b[i]*2)%m;
		c[i+1]=(c[i]*2)%m;
	}
	s[1]=1;
	s[2]=2;
	for(int i=3;i<10001;i++){
		s[i]=(8*s[i-2]+a[i]-b[i])%m;
	}
	ans[1]=0;
	for(int i=2;i<=10000;i++){		
		int u=i-(1+i)/2;
		ans[i]=(((c[i-1]-c[u-1])*c[i])%m+m-(s[i]*m2)%m-c[i-2])%m;
	}
	for(int i=1;i<=10000;i++){
		tt=(tt+ans[i])%m;
	}
	cout<<tt;
}
