#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

long long a[maxn],b[maxn];

long long n,k;

int main(){
	cin >> n >> k;
	if(n <= k) {
		cout << 1 << endl;
		return 0;
	}
	long long ans = 1e18;
	for(int i = 1;i < k;i++){
		a[1] = 0;
		b[1] = i;
		a[2] = b[1] + min(b[1],(n - b[1]) / 2);
		int j;
		for(j = 2;;j++){
			if(a[j] + (k - i) >= n) break;
			b[j] = a[j];
			a[j + 1] = b[j] + min(b[j],(n - b[j]) / 2);
		}	
		ans = min(ans,1LL * j);
	}
	cout << ans << endl;
	return 0;
}
