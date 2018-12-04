#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 505;

int r[maxn][maxn],c[maxn][maxn];
long long a[maxn][maxn];
int n,m;
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			scanf("%d%d",&r[i][j],&c[i][j]);
		}
	}
	bool flag = true;
	for(int i = 0;i < n;i++){
		if(i == 0){
			a[i][0] = 0;
		}else{
			a[i][0] = r[i][0] + a[i - 1][0];
		}
		for(int j = 1;j < m;j++){
			a[i][j] = a[i][j - 1] - c[i][j]; 
		}
		if(a[i][m - 1] - a[i][0] != c[i][0]) flag = false;
		if(i == n - 1){
			for(int j = 0;j < m;j++){
				if(a[i][j] - a[0][j] != -r[0][j]) flag = false;
			}
		}
	}
	if(flag){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
