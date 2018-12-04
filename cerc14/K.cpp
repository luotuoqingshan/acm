#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 150000 + 5;
pair<int,int> a[maxn];
int n,k;
int dp[maxn][12];
void solve(){
	sort(a + 1,a + 1 + n);	
	if(n <= k){
		printf("0\n");
		return;
	}
	int l = 0,r = INF;
	while(l < r){
		int mid = (l + r + 1) / 2;
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= k + 2;j++){
				dp[i][j] = INF;
			}
		}	
		dp[0][0] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= k + 1;j++){
				dp[i][j] = min(dp[i][j],dp[i - 1][j]);
				if(j > 0 && a[i].first - a[i].second - dp[i - 1][j - 1] >= mid){
					dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + a[i].second);
				}
			}
		}
		if(dp[n][k + 1] < INF) l = mid;
		else r = mid - 1;
	}
	printf("%d\n",l);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++){
			scanf("%d%d",&a[i].first,&a[i].second);
		}
		solve();
	}
	return 0;
}
