#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T;

int n;

long long a[20];

int cal(long long x){
	int cnt = 0;
	while(x > 0){
		x -= x & -x;
		cnt++;
	}
	return cnt;
}

long long ans;

void dfs(int i,long long x,long long zheng){
	ans += ((1LL << cal(x))) * zheng;
	for(int j = i + 1;j <= n;j++){
		dfs(j,x & a[j],-2 * zheng);
	}
}

int main(){
	int T;
	cin >> T;
	int cas = 0;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++){
			dfs(i,a[i],1);
		}
		printf("Case #%d: ",++cas);
		cout << ans << endl;
	}
	return 0;
}
