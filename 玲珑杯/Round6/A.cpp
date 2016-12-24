#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int maxn = 1005;

LL f[maxn][maxn],s[maxn][maxn];

int T;
int n,m;
int a[10];
int b[maxn];
int sum[maxn];

LL cal(int s){
	long long tmp = 1;
	long long ret = 0;
	for(int i = 0;i <= m;i++){
		ret += tmp * a[i];
		tmp = tmp * s;
	}
	return ret;
}
int main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d",b + i);
		}
		sum[0] = 0;
		for(int i = 1;i <= n;i++){
			sum[i] = sum[i - 1] + b[i];
		}
		cin >> m;
		for(int i = 0;i <= m;i++){
			scanf("%d",&a[i]);
		}
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		for(int len = 1;len <= n;len++){
			for(int i = 1;i <= n - len + 1;i++){
				int j = i + len - 1;
				if(len == 1){
					f[i][j] = 0;s[i][j] = i;
				}else{
					for(int k = s[i][j - 1];k <= s[i + 1][j];k++){
						if(f[i][j] == 0 || f[i][j] > f[i][k] + f[k + 1][j] + cal(sum[j] - sum[i - 1])){
							s[i][j] = k;
							f[i][j] = f[i][k] + f[k + 1][j] + cal(sum[j] - sum[i - 1]);
						}
					}
				}
			}
		}
		cout << f[1][n] << endl;
	}
	return 0;
}
