#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
const int maxn = 1e6 + 5;

int a[maxn];
int cnt[maxn];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1;i < maxn;i++){
		for(int j = 2 * i;j < maxn;j += i){
			cnt[i] += cnt[j];
		}
	}
	int ans = 0;
	for(int i = 1;i < maxn;i++){
		if(cnt[i] > 1)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}
