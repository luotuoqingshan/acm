#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

LL qpow(LL a,LL n){
	LL ans = 1;
	while(n > 0){
		if(n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
	}else{
		cout << qpow(n,(n - 1) * (n - 1)) << endl;
	}
	return 0;
}
