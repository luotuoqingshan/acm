#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

long long n,k;

int main(){
	while(cin >> n >> k){
		long long d = n % (k + 1);
		if(d == 0){
			printf("%lld\n",n / (k + 1) * 2);
		}else if(d == 1){
			printf("%lld\n",n / (k + 1) * 2 + 1);
		}else{
			printf("%lld\n",n / (k + 1) * 2 + 2);
		}
	}
	return 0;
}
