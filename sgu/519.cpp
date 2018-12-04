#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


const int maxn = 105;

int a[maxn][maxn];
char s[maxn][maxn];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

int main(){
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%s",s[i] + 1);
		for(int j = 1;j <= m;j++){
			a[i][j] = s[i][j] - '0';
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] != 0) ans += 2;
			for(int k = 0;k < 4;k++){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(a[i][j] > a[nx][ny]){
					ans += a[i][j] - a[nx][ny];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
