#include<bits/stdc++.h>
using namespace std;
int a[41][41];
int s=0;
double ans=1.0;
int main(){
	a[0][0]=1;
	for(int i=1;i<41;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) a[i][j]=1;
			else a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(int i=1;i<=5;i++){
		ans=ans/a[8*i][8];
		while(ans<1){
			ans=ans*10;
			s++;
		}
	}
	for(int i=1;i<=8;i++){
		ans=ans/a[5*i][5];
		while(ans<1){
			ans=ans*10;
			s++;
		}
	}
	printf("%.10lf",ans);
	printf("e-");
	printf("%d",s);
}
