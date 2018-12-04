#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

long long a,b;

int main(){
	long long ans = 0;
	cin >> a >> b;
	for(long long i = 1;i <= 1e6;i++){
		long long l = (a + i - 1) / i * i;
		long long r = (b / i) * i;
		for(long long j = l;j <= r;j += i){
			if(j / i > i){
				ans += i + j / i;	
			}else if(j / i == i){
				ans += j / i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

