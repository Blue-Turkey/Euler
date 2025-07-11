#include<bits/stdc++.h>
using namespace std;
const int n=1e7;
const int m=n/2;
int ans1[n+5];
int ans2[n+5];
int key[n+5];
int s;
int u;
int sum=n+1;
int f(int j,int i){
	int k=j;
	int ans=0;
	int aa=i;
	while(k>0){
		if(k%2){
			ans=ans^aa;
		}
		k=k/2;
		aa=aa*4;
	}
	return ans;
}

int main(){
//	for(int i=0;i<s;i++) cout<<t[i]<<endl;
	u=4;
	for(int i=1;i<=n;i++){
		while(u<=4*n){
			for(int j=u/2;j<=n;j=j+u) key[j]=-1;
			u=u*4;
		}
	}
	s=1;
	for(int i=1;i<=n;i++){
		if(key[i]==0){
			int l=log2(i);
			int c=13-l/2;
			if(c>12) c=12;
			c=1<<c;
			for(int j=1;j<c;j++){
				u=f(j,i);
				if(u<=n){
					key[u]=s;
					ans1[s]++;
					if(u<=m) ans2[s]++;
				}
			}
			s++;
		}
	}
	for(int i=1;i<s;i++) sum=sum+ans1[i]*ans2[i];
	cout<<sum;
}
