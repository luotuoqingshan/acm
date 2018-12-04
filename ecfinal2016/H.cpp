#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int N,M,K;

typedef long long LL;

const LL mod = 1e9 + 7;

LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

int main(){
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		cin >> N >> M >> K;
		LL ret = 0;
		ret = (ret + qpow(K,N * M)) % mod;
		LL ans = 0;
		for(int i = 2;i <= K;i++){
			ans += qpow(i - 1,N + M - 2);
			ans %= mod;
		}
		ans = ans * qpow(K,(N - 1) * (M - 1)) % mod;
		ans = ans * (N * M) % mod;
		ans = (ans + ret) % mod;
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
