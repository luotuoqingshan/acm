#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int n;long long m;

typedef long long ll;

long long qpow(ll a,ll n){
	ll ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a;
		a = a * a;
		n >>= 1;
	}
	return ret;
}

int divi[10000];
int cnt;

int main(){
	while(cin >> n >> m){
		cnt = 0;
		long long K = m;
		for(int i = 2;i * i <= m;i++){
			if(m % i == 0){
				divi[cnt++] = i;
				while(m % i == 0) m /= i;
			}
		}
		if(m > 1) divi[cnt++] = m;
		long long ans  = 0;
		for(int i = 0;i < (1 << cnt);i++){
			int num = 0;
			ll mul = 1;
			for(int j = 0;j < cnt;j++){
				if((i >> j) & 1){
					num++;
					mul *= divi[j];
				}
			}
			if(num & 1){
				ll tmp = qpow(K / mul,n);
				ans -= tmp;
			}else{
				ll tmp = qpow(K / mul,n);
				ans += tmp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
