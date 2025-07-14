#include<bits/stdc++.h>
using namespace std;
long long n3[19][19];
long long n5[19][19];
bool flag;
long long f(long long a,long long b){
	long long x,y;
	x=min(a,b);
	y=max(a,b);
	if(x==0){
		return 0;
	}
	else{
		return f(y%x,x)+y/x;		
	}
}
long long ans(int k){
	long long sum=0;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			for(int s=0;s<=k;s++){
				if(i>0||j*2<k||(j*2==k&&s*2<=k)){
					long long a1=n3[i][j];
					long long b1=n5[0][s];
					long long a2=n3[0][k-j];
					long long b2=n5[i][k-s];
//					cout<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<endl; 
					long long ans1=min(f(a1,b1),f(a2,b2));
					if(a1<b1&&a2<b2) ans1=ans1*2-1;
//					cout<<ans1<<endl;
					sum=sum+ans1; 
				}
			}
		}
	}
	return sum;
}
int main(){
	n3[0][0]=1;
	n5[0][0]=1;
	for(int i=1;i<19;i++){
		n3[i][0]=n3[i-1][0]*2;
		n5[i][0]=n5[i-1][0]*2;
	}
	for(int i=0;i<19;i++){
		for(int j=1;j<19;j++){
			n3[i][j]=n3[i][j-1]*3;
			n5[i][j]=n5[i][j-1]*5;
		}
	}
	long long v=0;
	for(int i=1;i<=18;i++) v=v+ans(i);
	cout<<v;
}
