#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int W,S;
int X,Y;
const int maxn = 10005;
int a[maxn][105];
int b[maxn][105];
int c[105];
int main(){
	cin >> W >> S;
	cin >> X >> Y;
	for(int i = 1;i <= W;i++){
		for(int j = 1;j <= X;j++){
			scanf("%d",&a[i][j]);
		}
	}	
	for(int i = 1;i <= X;i++)
		c[i] = 1e9;
	for(int i = 1;i <= S;i++){
		for(int j = 1;j <= X;j++){
			scanf("%d",&b[i][j]);
			c[j] = min(c[j],Y - b[i][j]);
		}
	}
	for(int i = 1;i <= W;i++){
		for(int j = 1;j <= X;j++){
			a[i][j] = min(a[i][j],c[j]);
			printf("%d%c",a[i][j],j == X ? '\n' : ' ');
		}
	}
	return 0;
}
