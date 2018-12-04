#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 5;
int cnt[5005];
int a[maxn];
int n;
long long k;

long long count(long long val){
	memset(cnt,0,sizeof(cnt));
	int r = 0;
	long long now = 0;
	long long ans = 0;
	for(int l = 1;l <= n;l++){
		while(r < n){
			if(now + cnt[a[r + 1]] <= val){
				r++;
				now += cnt[a[r]];
				cnt[a[r]]++;
			}else break;
		}
		ans += r - l + 1;
		cnt[a[l]]--;
		now -= cnt[a[l]];
		//cout << ans << endl;
	}
	return ans;
}
int main(){
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		long long l = 0, r = 1e18;
		//cout << count(6) << endl;
		while (l < r) {
			long long mid = (l + r) / 2;
			if (count(mid) >= k) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}

/*
 4 7
1 1 2 3
3 6
100 100 100
0
3
 100 4123
47 134 131 81 150 82 27 81 85 87 55 9 56 70 37 114 123 93 88 80 28 55 121 44 143 97 139 61 133 55 23 126 80 76 87 10 10 64 70 9 113 25 15 133 88 112 81 83 25 37 86 71 44 37 36 15 31 19 24 86 100 95 55 37 3 61 47 136 6 101 2 37 134 58 129 124 10 107 129 38 43 103 45 70 150 56 77 106 109 6 84 4 130 116 141 21 122 42 3 118
 */
