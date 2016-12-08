#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

long long prime[200];
bool vis[200];
int cnt;

void init(){
	cnt = 0;
	for(int i = 1;i < 200;i++) vis[i] = true;
	vis[1] = false;
	for(int i = 2;i < 200;i++) if(vis[i]){
		prime[++cnt] = i;
		for(int j = i * 2;j < 200;j += i){
			vis[j] = false;
		}
	}
}

int main(){
	long long n;
	init();
	while(cin >> n){
		int m = 0;
		for(int i = 1;i <= cnt;i++){
			if(1LL << prime[i] > n){
				m = i - 1;
				break;
			}
		}
		long long ans = 0;
		for(int i = 1;i < (1LL << m);i++){
			long long tmp = 1,res = 0;
			for(int j = 0;j < m;j++){
				if((i >> j) & 1){
					res++;
					tmp *= prime[j + 1];
				}
			}
			if(res > 3) continue;
			long long ret = (long long)(pow(n,1.0 / tmp) + 1e-6) - 1;
			if(res & 1) ans += ret;
			else ans -= ret;
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
