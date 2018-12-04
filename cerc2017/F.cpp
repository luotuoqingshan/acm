#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

long long n;
int p,r;

int qpow(int a,int n,int mod){
	int ret = 1;
	while(n > 0){
		if(n & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}

const int maxn = 1e7 + 5;
int fac[maxn],inv[maxn];
int INV[maxn];


int main(){
	cin >> n >> p >> r;
	if(n >= 2 * p){
		if(r != 0){
			printf("-1 -1\n");
			return 0;
		}else{
			printf("2 1\n");
			return 0;
		}
	}else if(n >= p){
		if(r != 0){
			int temp = 1;
			for(int i = 1;i <= n;i++){
				if(i == p) continue;
				temp = 1LL * temp * i % p;
			}		
			temp = 1LL * qpow(temp,p - 2,p) * r % p;
			if(temp < p){
				printf("%d %d\n",p,temp);
				return 0;
			}else{
				printf("-1 -1\n");
				return 0;
			}
		}else{
			if(n > p){
				printf("%lld %d\n",n,p);
			}else{
				if(n == 2){
					printf("-1 -1\n");
				}else{
					printf("2 1\n");	
				}
			}
			return 0;
		}
	}else{
		if(r == 0){
			printf("-1 -1\n");
			return 0;
		}
		fac[0] = 1;
		for(int i = 1;i <= n;i++)
			fac[i] = fac[i - 1] * 1LL * i % p;
		inv[n] = qpow(fac[n],p - 2,p);
		INV[1] = 1;
		bool flag = false;
		for(int i = 2;i <= n;i++){
			int temp = 1LL * inv[n] * i % p;
			temp = 1LL * temp * r % p;
			if(temp < i){
				flag = true;
				printf("%d %d\n",i,temp);
				break;
			}
		}
		if(!flag) printf("-1 -1\n");
	}
	return 0;
}
