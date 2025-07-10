#include<bits/stdc++.h>
using namespace std;
const int n=123456;
long long a[2*n+10];
long long c[5+n],d[5+n];
int e[n+5],f[5+n];
double r[n+10];
int main(){
	freopen("a.out","w",stdout);
	r[1]=1.0;
	r[2]=2.0;
	c[1]=2;
	d[1]=1;
	for(int i=2;i<n;i++){
		a[1]=1;
		a[2]=2;
		r[i+1]=123456.0;
		int t=1;
//		cout<<1<<' '<<2<<' ';
		for(int j=3;j<2*i+5;j++){
			while(a[j-1]*d[i-1]-c[i-1]*a[t]>0)t++;
			a[j]=a[j-1]+a[t];
			if(a[j]>1000000000) goto A;
			if(t>1){
				if(r[i+1]>(double)a[j-1]/(double)(a[t-1])){
					r[i+1]=(double)a[j-1]/(double)(a[t-1]);
					c[i]=a[j-1];
					d[i]=a[t-1];
					e[i]=j-1;
					f[i]=t-1;
				}
			}
//			cout<<a[j]<<' ';
		}
		A:;
//		cout<<endl;
	}
	
	for(int i=1;i<n;i++){
		cout<<c[i]<<' '<<d[i]<<endl;
		cout<<e[i]<<' '<<f[i]<<endl;
//		cout<<r[i]<<endl;
////		for(int j=1;j<60;j++){
////			cout<<a[i][j]<<' ';
////		}
////		cout<<endl;
////		for(int j=1;j<60;j++){
////			cout<<b[i][j]<<' ';
////		}
		cout<<endl;
	}
// The answer is c[123455]/d[123455]. Then use calculator to get it. 
}
