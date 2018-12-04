#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int b,a;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int N = 1e5;

int fac[maxn],inv[maxn];

int qpow(int a,int n){
	int ret = 1;
	while(n > 0){
		if(n & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}
void init(){
	fac[0] = 1;
	for(int i = 1;i <= N;i++){
		fac[i] = 1LL * fac[i - 1] * i % mod;
	}
	inv[N] = qpow(fac[N],mod - 2);
	for(int i = N - 1;i >= 0;i--){
		inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	}
}

int C(int n,int m){
	return fac[n] * 1LL * inv[m] % mod * inv[n - m] % mod;
}

int main(){
	init();
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d",&a,&b);
		printf("%lld\n",2LL * C(a - 1,b) % mod);
	}
	return 0;
}
