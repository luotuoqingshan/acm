#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;

LL a[maxn];
int main(){
	int K;
	cin >> K;
	for(int i = 1;i <= K;i++){
		scanf("%lld",a + i);
	}
	bool flag = 1;
	LL L = 2,R = 2;
	for(int i = K;i >= 1;i--){
		LL l = (L + a[i] - 1) / a[i];
		LL r = R / a[i];
		if(l > r){
			flag = 0;
			break;
		}else{
			L = l * a[i];
			R = (r + 1) * a[i] - 1;
		}
	}
	if(flag){
		cout << L << " " << R << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}
