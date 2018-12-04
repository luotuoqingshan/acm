#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

void init(LL maxn){
	for(LL k = 1;k < maxn;k++){
		LL a = 3LL * (k - 1) * (k + 1);
		LL b = sqrt(a);
		while((b + 1) * (b + 1) <= a)b++;
		if(b * b == a){
			cout << k << endl;
		}
	}
}

int main(){
	init(100000000);
	return 0;
}
