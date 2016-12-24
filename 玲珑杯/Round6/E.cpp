#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 205;
int T;
int dp[maxn][maxn];
char s[maxn];

int Dp(int l,int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l >= r) return 0;
	int ret = Dp(l + 1,r) + 1;
	for(int i = l + 1;i < r;i++){
		if(s[i] == s[l]){
			ret = min(ret,Dp(l + 1,i) + Dp(i,r));
		}
	}
	return dp[l][r] = ret;
}

int main(){
	cin >> T;
	while(T--){
		int n;
		scanf("%s",s + 1);
		n = strlen(s + 1);
		memset(dp,-1,sizeof(dp));
		cout << Dp(1,n + 1) << endl;
	}
	return 0;
}
