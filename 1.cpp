#include<bits/stdc++.h>
using namespace std;
long long n;
vector<int>a;
long long m=1e9+7;
int c=0;
int sum=0;
long long s2=(m+1)/2;
long long s3=(m+1)/3;
long long c2(long long x){
	long long k=x%m;
	return (k*(k-1)/2)%m;
}
long long c3(long long x){
	long long k=x%m;
	return ((((k*(k-1)/2)%m)*(k-2))%m*s3)%m;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	long long b=n;
	while(b){
		a.push_back(b%2);
		b=b/2;
		c++;
	}
//	for(int i=a.size()-1;i>=0;i--)cout<<a[i];
	int k=1;
	long long t=1;
	while(n-t>t){
		sum=(sum+(c3(2*t+3)-c3(t+3))%m*(k%m))%m;
//		cout<<sum<<endl;
		t=t*2;
		k++;
	}
	sum=(sum+(c3(n+3)-c3(t+3))%m*(k%m))%m;	
//	cout<<sum;
	b=n;
	long long p=log2(b-1);
	long long q=1;
	t=1;
	for(int i=1;i<=p;i++)q=q*2;
	long long r=q-(n-q);
	if(b-q>q/2){
		sum=(sum+t*((4*(c3(b-q+1)-c3(q/2+1)))%m-(((2*q+1)%m)*(c2(b-q+1)-c2(q/2+1)))%m+((b-q-q/2)%m*c2(q+2))%m)%m)%m;
	}
	b=q;
	q=q/2;
	while(q>=4){
		sum=(sum+t*((4*(c3(b-q+1)-c3(q/2+1)))%m-(((2*q+1)%m)*(c2(b-q+1)-c2(q/2+1)))%m+((b-q-q/2)%m*c2(q+2))%m)%m)%m;
		if(b-q-r>=q/2+1){
			sum=(sum+(2*t+1)*((4*(c3(b-q-r+1)-c3(q/2+1)))%m-(((2*q+1)%m)*(c2(b-q-r+1)-c2(q/2+1)))%m+((b-q-r-q/2)%m*c2(q+2))%m)%m)%m;
		}
		t=(3*t+1)%m;
		b=q;
		q=q/2;
	}
	sum=sum%m;
	if(sum<0) sum=sum+m;
//	long long u=1<<33;
//	cout<<u<<endl;
	cout<<sum;
	
}
