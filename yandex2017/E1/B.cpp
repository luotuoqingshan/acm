#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long a,n;

int main(){
	cin >> n >> a;	
	long long ans = 0;
	for(int i = 0;i <= 1000;i++){
		long long a1 = a + i;
		long long a2 = n - a1;
		if(a2 < a) break;
		ans = max(ans,(1000 - a1 % 500) % 500 + (1000 - a2 % 500) % 500);
	}
	cout << ans << endl;
	return 0;
}
