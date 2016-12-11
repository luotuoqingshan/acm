#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1005;

int a[maxn][maxn];

int main(){
	int n;
	while(cin >> n){
		int l = 1,r = 6 * n * n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				a[i][j] = l++;
				a[3 * n + 1 - i][j] = r--;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				a[i + n][j] = l++;
				a[i + n][3 * n + 1 - j] = r--;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				a[i + n][j + n] = l++;
				a[i + n][4 * n + 1 - j] = r--;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				printf("%d%c",a[i][j],j == n ? '\n' : ' ');
			}
		}
		for(int i = n + 1;i <= 2 * n;i++){
			for(int j = 1;j <= 4 * n;j++){
				printf("%d%c",a[i][j],j == 4 * n ? '\n' : ' ');
			}
		}
		for(int i = 2 * n + 1;i <= 3 * n;i++){
			for(int j = 1;j <= n;j++){
				printf("%d%c",a[i][j],j == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}
