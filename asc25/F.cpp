#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 100000 + 5;

int t[maxn];
int dp[maxn][2][2];
char s[maxn];
int n;
int m;
void upd(int &a,int b){
	if(b > a){
		a = b;
	}
}
void dfs(int u){
	if(s[u] == 'g'){
		t[u] = 0;
		dp[u][0][0] = 0;
		dp[u][1][0] = 1;
		dp[u][0][1] = 1;
		dp[u][1][1] = 0;
		return;
	}
	int L,R;
	m++;
	L = m;
	dfs(m);
	m++;
	R = m;
	dfs(m);
	if(s[u] == 'P'){
		upd(dp[u][0][0],dp[L][0][0] + dp[R][0][0]);
		upd(dp[u][0][1],dp[L][0][1] + dp[R][0][1] - 1);
		upd(dp[u][1][0],dp[L][1][0] + dp[R][1][0] - 1);
		upd(dp[u][1][1],dp[L][1][1] + dp[R][1][1] - 2);
	}else{
		upd(dp[u][0][0],dp[L][0][0] + dp[R][0][0]);
		upd(dp[u][0][0],dp[L][0][1] + dp[R][1][0] - 1);
		upd(dp[u][0][1],dp[L][0][0] + dp[R][0][1]);
		upd(dp[u][0][1],dp[L][0][1] + dp[R][1][1] - 1);
		upd(dp[u][1][0],dp[L][1][0] + dp[R][0][0]);
		upd(dp[u][1][0],dp[L][1][1] + dp[R][1][0] - 1);
		upd(dp[u][1][1],dp[L][1][0] + dp[R][0][1]);
		upd(dp[u][1][1],dp[L][1][1] + dp[R][1][1] - 1);
	}	
}

int main(){
	memset(dp,0,sizeof(dp));
	scanf("%s",s + 1);	
	n = strlen(s + 1);
	m = 1;
	dfs(m);
	int ans = 0;
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 2;j++){
			upd(ans,dp[1][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
