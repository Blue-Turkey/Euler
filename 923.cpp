#include<bits/stdc++.h>
using namespace std;
const int z=64;
const int y=8;
long long big=1e9+7;
const int mid=(z+1)*(y+1);
long long b[z][y+1][2*mid];
long long s[z][y+1][2*mid];
long long b1[z][y+1][2*mid];
long long num[z][2*z+3];
long long c[y+1][y+1];
vector<int>g[z];
int main(){
	c[0][0]=1;
	for(int i=1;i<=y;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) c[i][j]=1;
			else c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(int i=1;i<z;i++){
		for(int j=1;j<z-i;j++){
			for(int k=1;k<=z-i-j;k++){
				if((k*i)%(i+j)==0){
					g[i+j].push_back(-i);
				}
				else{
					int t=(k*i)/(i+j);
					g[0].push_back((t+1)*j-(k-t)*i);
				}
			}
		}
	}
//	for(int i=0;i<z;i++){
//		for(int j=0;j<g[i].size();j++) cout<<g[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=0;i<z;i++){
		for(int j=0;j<g[i].size();j++) num[i][g[i][j]+z]++;
	}
//	b[0][0][mid]=1;
//	for(int i=1;i<=y;i++){
//		for(int j=0;j<2*mid;j++){
//			for(int k=0;k<(2*z+3);k++){
//				if(j+z-k<2*mid&&j+z-k>=0) b[0][i][j]=(b[0][i][j]+num[0][k]*b[0][i-1][j+z-k])%big;
//			}
//		}
//	}
//	for(int i=0;i<=y;i++){
//		for(int j=0;j<2*mid;j++){
//			s[0][i][j]=b[0][i][j];
//		}
//	}
	for(int r=0;r<z;r++){
		b1[r][0][mid]=1;
		for(int i=1;i<=y;i++){
			for(int j=0;j<2*mid;j++){
				for(int k=0;k<(2*z+3);k++){
					if(j+z-k<2*mid&&j+z-k>=0) b1[r][i][j]=(b1[r][i][j]+num[r][k]*b1[r][i-1][j+z-k])%big;
				}
			}
		}
	}
//	for(int r=0;r<z;r++){
//		for(int i=0;i<=y;i++){
//			for(int j=0;j<2*mid;j++){
//				cout<<b1[r][i][j]<<' ';
//			}
//			cout<<endl;
//		}
//	}
	for(int i=0;i<=y;i++){
		for(int j=0;j<2*mid;j++){
			b[0][i][j]=b1[0][i][j];
			s[0][i][j]=b1[0][i][j];
		}
	}
	for(int i=1;i<z;i++){
		b[i][0][mid]=1;
		s[i][0][mid]=1;
		for(int j=1;j<=y;j++){
			for(int k=0;k<2*mid;k++){
				for(int l=0;l<=j;l++){
					for(int t=0;t<2*mid;t++){
						if(l%2==0){
							if(mid+k-t-l/2*i>=0&&mid+k-t-l/2*i<2*mid){ 
								b[i][j][k]=(b[i][j][k]+b1[i][l][t]*((c[j][l]*b[i-1][j-l][mid+k-t-l/2*i])%big))%big;
								s[i][j][k]=(s[i][j][k]+b1[i][l][t]*((c[j][l]*s[i-1][j-l][mid+k-t-l/2*i])%big))%big;
							}
						}
						else{
							if(mid+k-t-(l+1)/2*i>=0&&mid+k-t-(l+1)/2*i<2*mid) b[i][j][k]=(b[i][j][k]+b1[i][l][t]*((c[j][l]*s[i-1][j-l][mid+k-t-(l+1)/2*i])%big))%big;
							if(mid+k-t-l/2*i>=0&&mid+k-t-l/2*i<2*mid) s[i][j][k]=(s[i][j][k]+b1[i][l][t]*((c[j][l]*b[i-1][j-l][mid+k-t-l/2*i])%big))%big;
						}
					}
				}
			}
		}
	}
//	for(int r=0;r<z;r++){
//		for(int i=0;i<=y;i++){
//			for(int j=0;j<2*mid;j++){
//				cout<<b[r][i][j]<<' ';
//			}
//			cout<<endl;
//		}
//	}
	long long sum=0;
	for(int i=mid+1;i<2*mid;i++){
		sum=(sum+b[z-1][y][i])%big;
	}
	cout<<sum;
//	for(int i=0;i<g[0].size();i++){
//		cout<<g[0][i].first<<' '<<g[0][i].second<<endl;
//	}
}
