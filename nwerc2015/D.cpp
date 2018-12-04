#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 2e6 + 5;
LL n,r,p;
LL dp[maxn];

void upd(LL &a,LL b){
	if(b < a) a = b;
}

int main(){
	cin >> n >> r >> p;
	for(int i = 1;i <= 2 * n;i++){
		dp[i] = 1e18;
	}
	dp[1] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 2 * i;j <= 2 * n;j += i){
			upd(dp[j],((j / i) - 1) * p + r + dp[i]);
		}
	}
	for(int i = n + 1;i <= 2 * n;i++){
		upd(dp[n],dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}
