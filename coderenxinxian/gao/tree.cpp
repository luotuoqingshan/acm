#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

void upd(LL &a,LL b){
	a += b;
	if(a >= mod) a -= mod;
}

struct mat{
	LL a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	mat operator * (mat b){
		mat c;
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 2;j++){
				for(int k = 0;k < 2;k++){
					upd(c.a[i][k],1LL * a[i][j] * b.a[j][k] % mod);
				}
			}
		}
		return c;
	}
};

mat qpow(mat a,LL n){
	mat b;
	b.a[0][0] = b.a[1][1] = 1;
	while(n > 0){
		if(n & 1) b = b * a;
		a = a * a;
		n >>= 1;
	}
	return b;
}

LL n,k;


int main(){
	cin >> n >> k;
	if(k == 1){
		cout << 1 << endl;
	}else{
		if(n <= 2){
			cout << 1 << endl;
		}else{
			mat a;
            a.a[0][0] = 1;
			a.a[0][1] = 1;
			a.a[1][0] = 1;
			a.a[1][1] = 2;
            a = qpow(a,n - 2);
			cout << (a.a[1][0] + a.a[1][1]) % mod << endl;
		}
	}
	return 0;
}
