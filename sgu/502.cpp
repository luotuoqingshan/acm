#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = (1 << 18) + 5;

bool dp[maxn][20];
int  pre[maxn][20];

int d[20];
long long n;
int a[20],tot;

int main(){
	d[0] = 1;
	tot = 0;
	cin >> n;
	while(n > 0){
		a[tot++] = n % 10;
		n /= 10;
	}
	for(int i = 1;i < 20;i++){
		d[i] = d[i - 1] * 10 % 17;
	}	
	memset(dp,0,sizeof(dp));
	memset(pre,-1,sizeof(pre));
	dp[0][0] = 1;
	for(int i = 1;i < (1 << tot);i++){
		int len = __builtin_popcount(i);
		for(int j = 0;j < tot;j++){
			if(i & (1 << j)){
				if(a[j] == 0 && i == (1 << tot) - 1)
					continue;
				for(int k = 0;k < 17;k++)
					if(dp[i ^ (1 << j)][k]){
						dp[i][(k + a[j] * d[len - 1]) % 17] = true;
						pre[i][(k + a[j] * d[len - 1]) % 17] = j;
					}
			}
		}
	}	
	if(dp[(1<<tot) - 1][0]){
		int now = (1 << tot) - 1;
		int sum = 0;
		while(pre[now][sum] != -1){
			int p = pre[now][sum];
			now ^= (1 << p);
			int len = __builtin_popcount(now);
			sum = (sum - a[p] * d[len] % 17 + 17) % 17;
			printf("%d",a[p]);
		}	
		puts("");
	}else{
		cout << -1 << endl;
	}
	return 0;
}

