#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e6 + 5;

int dp[maxn][2];
char s[maxn];
const int INF = 0x3f3f3f3f;
int main(){
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	for(int i = 2;i <= n + 1;i++){
		dp[i][1] = dp[i][0] = INF;
	}
	dp[1][1] = 1;	
	dp[1][0] = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '0'){
			dp[i + 1][1] = min(dp[i + 1][1],dp[i][0] + 1);
			dp[i + 1][1] = min(dp[i + 1][1],dp[i][1] + 1);
			dp[i + 1][0] = min(dp[i + 1][0],dp[i][0]);
		}else{
			dp[i + 1][1] = min(dp[i + 1][1],dp[i][1]);
			dp[i + 1][0] = min(dp[i + 1][0],dp[i][1] + 1);
		}
	}
	cout << dp[n + 1][0]  * 2 - 1<< endl;
	return 0;
}
