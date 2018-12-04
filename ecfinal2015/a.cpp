#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int T;
long long n;

int main(){
	int cas = 0;
	cin >> T;
	while(T--){
		cin >> n;
		long long a = sqrt(2 * n);
		a = max(1LL,a - 5);
		while((a + 1) * (a + 2) <= 2 * n) a++;
		printf("Case #%d: %lld\n",++cas,a * (a + 1) / 2);
	}
	return 0;
}
