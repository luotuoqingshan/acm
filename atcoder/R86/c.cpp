#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 200000 + 5;

int k,n;
int cnt[maxn];
int a[maxn],tot;

int main(){
	cin >> n >> k;
	tot = 0;
	for(int i = 1;i <= n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i = 1;i <= n;i++){
		if(cnt[i] > 0){
			a[++tot] = cnt[i];
		}
	}
	sort(a + 1,a + 1 + tot);
	int ans = 0;
	for(int i = 1;i <= tot - k;i++){
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}
