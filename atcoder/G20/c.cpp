#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int n;
const int maxn = 2005;
int a[maxn];

bitset<4000005> dp;
int main(){
	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	dp.set(0);
	for(int i = 1;i <= n;i++){
		dp |= (dp << a[i]);
	}
	int ans = sum;
	for(int i = 0;i <= sum;i++){
		if(dp.test(i) == 1){
			if(i * 2 >= sum){
				ans = min(ans,i);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
