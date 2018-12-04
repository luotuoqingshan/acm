#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int S = 100;

long long mult_mod(long long a,long long b,long long c){
	a %= c;
	b %= c;
	long long ret = 0;
	long long tmp = a;
	while(b){
		if(b & 1){
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}

long long pow_mod(long long a,long long n,long long mod){
	long long ret = 1;
	long long temp = a % mod;
	while(n){
		if(n & 1) ret = mult_mod(ret,temp,mod);
		temp = mult_mod(temp,temp,mod);
		n >>= 1;
	}
	return ret;
}

bool check(long long a,long long n,long long x,long long t){
	long long ret = pow_mod(a,x,n);
	long long last = ret;
	for(int i = 1;i <= t;i++){
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1 && last != n - 1) return 1;
		last = ret;
	}
	if(ret != 1) return 1;
	else return 0;
}

bool Miller_Rabin(long long n){
	if(n < 2) return 0;
	if(n == 2) return 1;
	if((n & 1) == 0) return 0;
	long long x = n - 1;
	long long t = 0;
	while((x & 1) == 0){x >>= 1;t++;}
	srand(time(0));
	for(int i = 0;i < S;i++){
		long long a = rand() % (n - 1) + 1;
		if(check(a,n,x,t))
			return false;
	}
	return 1;
}

long long N;
int a[20],tot;

int main(){
	cin >> N;
	tot = 0;
	if(!Miller_Rabin(N)){
		cout << "no" << endl;
		return 0;
	}
	while(N > 0){
		a[tot++] = N % 10;
		N /= 10;
	}
	for(int i = 0;i < tot;i++){
		if(a[i] == 6) a[i] = 9;
		else if(a[i] == 9) a[i] = 6;
		if(a[i] == 3 || a[i] == 4 || a[i] == 7){
			cout << "no" << endl;
			return 0;
		}
	}
	
	for(int i = 0;i < tot;i++){
		N = N * 10 + a[i];
	}
	if(!Miller_Rabin(N)){
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	return 0;
}
