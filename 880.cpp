#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long m=1031*1031*1031+2;
long long n=1e15;
long long limit=sqrt(sqrt(n));
long long gcd(long long x,long long y){
	if(x==0) return y;
	if(y==0) return x;
	if(x>y) return gcd(x%y,y);
	return gcd(x,y%x);
}
long long f(long long x){
	long long y=x%m;
	long long ans=((y+1)*y/2);
	if(y%3==1) return (((2*y+1)/3)*(ans%m))%m;
	return (((2*y+1)%m)*((ans/3)%m))%m;
}
int main(){
//	cout<<limit<<endl;
//	cout<<m<<endl;
	for(long long i=1;i<=limit;i++){
		long long j=i;
		int flag=0;
		while(1){
			long long c=-i*i;
			long long b=2*j*j;
			long long a1=4*i*j;
			long long a2=-4*i*j;
			long long x1=abs((b-a1)*(b-a1)/b*(b-a1));
			long long y1=abs((c-a1)*(c-a1)/c*(c-a1));
			long long x2=abs((b-a2)*(b-a2)/b*(b-a2));
			long long y2=abs((c-a2)*(c-a2)/c*(c-a2));
			if((y1>n)&&flag%2==0) flag++;
			if((y2>n)&&flag<2) flag+=2;
			if(flag==3) goto A;
			else{
				if(gcd(2*j,i)==1){
					double s=cbrt(i);
					double t=cbrt(b);
					if((s-(int)(s)>0.00001&&s-(int)s<0.99999)||(t-(int)(t)>0.00001&&t-(int)t<0.99999)){
//						cout<<i<<' '<<j<<endl;
//						cout<<x1<<' '<<y1<<endl;
//						cout<<x2<<' '<<y2<<endl;
						long long z1=sqrt((n/(max(x1,y1))));
						long long z2=sqrt((n/(max(x2,y2))));
						sum=(sum+(((x1%m+y1%m)%m)*f(z1))%m+(((x2%m+y2%m)%m)*f(z2)%m)%m)%m;
					}
				}
			}
			j=j+1;
		}
		A:;
	}
	for(long long i=1;i<=limit;i++){
		long long j=i+1;
		int flag=0;
		while(1){
			long long c=-2*i*i;
			long long b=j*j;
			long long a1=4*i*j;
			long long a2=-4*i*j;
			long long x1=abs((b-a1)*(b-a1)/b*(b-a1));
			long long y1=abs((c-a1)*(c-a1)/c*(c-a1));
			long long x2=abs((b-a2)*(b-a2)/b*(b-a2));
			long long y2=abs((c-a2)*(c-a2)/c*(c-a2));
			if((y1>n)&&flag%2==0) flag++;
			if((y2>n)&&flag<2) flag+=2;
			if(flag==3) goto B;
			else{
				if(gcd(2*i,j)==1){
					double s=cbrt(j);
					double t=cbrt(-c);
					if((s-(int)(s)>0.00001&&s-(int)s<0.99999)||(t-(int)(t)>0.00001&&t-(int)t<0.99999)){
//						cout<<i<<' '<<j<<endl;
//						cout<<x1<<' '<<y1<<endl;
//						cout<<x2<<' '<<y2<<endl;
						long long z1=sqrt((n/(max(x1,y1))));
						long long z2=sqrt((n/(max(x2,y2))));
						sum=(sum+(((x1%m+y1%m)%m)*f(z1))%m+(((x2%m+y2%m)%m)*f(z2)%m)%m)%m;
					}
				}
			}
			j=j+1;
		}
		B:;
	}
	cout<<sum<<endl;
	return 0;
}
