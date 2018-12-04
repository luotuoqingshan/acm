#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;



const int maxn = 105;
typedef long long LL;


LL gcd(LL a,LL b){
	return b == 0 ? a : gcd(b,a % b);
}

LL lcm(LL a,LL b){
	LL g = gcd(a,b);
	return a / g * b;
}
const LL mod = (1LL << 31) - 1;
LL c[maxn][maxn];
LL inv[maxn];
LL fac[maxn];
map<LL,LL> mp;
void init(){
	memset(c,0,sizeof(c));
	c[0][0] = 1;
	for(int i = 1;i < maxn;i++){
		c[i][0] = 1;c[i][i] = 1;
		for(int j = 1;j < i;j++){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	inv[1] = 1;
	for(int i = 2;i < maxn;i++){
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	fac[0] = 1;
	for(int i = 1;i < maxn;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
}

LL cal(LL n,LL m,LL k,LL order){
	cout << n << " " << m << " " << k << " " << order << endl;
	if(n == 0) return order == k ? 1 : 0;
	if(m == 0) return 0;
	if(k % order != 0) return 0;
	LL chachenKey = (order * 110 + n) * 110 + m;
	if(mp.count(chachenKey)) return mp[chachenKey];
	LL sum = 0,temp = 1;
	for(int i = 0;i * m <= n;i++){
		LL temp2 = (temp * cal(n - i * m,m - 1,k,i == 0 ? order : lcm(order,m))) % mod;
		sum = (sum + temp2) % mod;
		cout << temp << " " << i << " " << n << " " << m << endl;
		temp = (temp * c[n - i * m][m]) % mod;
		temp = (temp * fac[m - 1]) % mod;
		cout << "#" << temp << endl;
		temp = (temp * inv[i + 1]) % mod;	
		cout << temp << endl;
	}
	mp[chachenKey] = sum;
	return sum;
}

LL n,k;
int main(){
	init();
	cin >> n >> k;
	cout << cal(n,n,k,1) << endl;
	return 0;
}
