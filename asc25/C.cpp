#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 786433;

typedef long long LL;

LL pow_mod(LL a,LL b,LL p){
	LL ret = 1;
	while(b > 0){
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}

const int maxn = (1 << 17) + 5;

namespace NTT{
	const int ort = 11;
	LL a[maxn],b[maxn],c[maxn];

	void ntt(LL A[],int n,int inv){
		LL w = 1,d = pow_mod(ort,(MOD - 1) / n,MOD),t;
		int i,j,c,s;
		if(inv == -1){
			for(int i = 1,j = n - 1;i < j;++i,--j)
				std::swap(A[i],A[j]);
			for(t = pow_mod(n,MOD - 2,MOD),i = 0;i < n;++i){
				A[i] = A[i] * t % MOD;
			}
		}
		for(s = n >> 1;s;s >>= w = 1,d = d * d % MOD){
			for(c = 0;c < s;++c,w = w * d % MOD){
				for(i = c;i < n;i += s << 1){
					A[i | s] = (A[i] + MOD - (t = A[i | s])) * w % MOD;
					A[i] = (A[i] + t) % MOD;
				}
			}
		}
		for(i = 1;i < n;++i){
			for(j = 0,s = i,c = n >> 1;c;c >>= 1,s >>= 1){
				j = j << 1 | s & 1;
			}
			if(i < j) std::swap(A[i],A[j]);
		}
	}
	void solve(LL *A,LL *B,LL *C,int n){
		int N = 1;
		while(N <= (n << 1)) N <<= 1;
		for(int i = n + 1;i < N;i++) A[i] = 0;
		for(int i = n + 1;i < N;i++) B[i] = 0;
		memcpy(b,B,sizeof(*B) * N);
		memcpy(a,A,sizeof(*A) * N);
		ntt(a,N,1);
		ntt(b,N,1);
		for(int i = 0;i < N;i++) c[i] = (LL) a[i] * b[i] % MOD;
		ntt(c,N,-1);
		ntt(a,N,-1);
		ntt(b,N,-1);
		for(int i = 0;i < N;i++) C[i] = c[i];
	}
}

int n,h;

LL dp[20][maxn];
LL tmpA[maxn],tmpB[maxn];
LL tmp[maxn];

void add(LL &a,LL b){
	a += b;
	if(a >= MOD) a -= MOD;
}

int main(){
	cin >> n >> h;
	h++;
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	dp[1][1] = 1;
	for(int i = 2;i <= h;i++){
		memset(tmp,0,sizeof(*tmp) * (1 << i));
		memcpy(tmpA,dp[i - 1],sizeof(*tmpA) * (1 << i));
		memcpy(tmpB,dp[i - 1],sizeof(*tmpB) * (1 << i));
		NTT::solve(tmpA,tmpB,tmp,(1 << i) - 1);
		for(int j = 0;j < maxn;j++){
			add(dp[i][j],tmp[j - 1]);
		}
		memset(tmp,0,sizeof(*tmp) * (1 << i));
		memcpy(tmpA,dp[i - 1],sizeof(*tmpA) * (1 << i));
		memcpy(tmpB,dp[i - 2],sizeof(*tmpB) * (1 << i));
		NTT::solve(tmpA,tmpB,tmp,(1 << i) - 1);
		for(int j = 0;j < maxn;j++){
			add(dp[i][j],tmp[j - 1]);
			add(dp[i][j],tmp[j - 1]);
		}
	}	
	cout << dp[h][n] << endl;
	return 0;
}
