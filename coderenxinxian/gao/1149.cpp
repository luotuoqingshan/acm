#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 500000 + 5;
char s[maxn];
string s1 = "coderenxinxian";
int dp[maxn][20];
int main(){
//	freopen("x1.in","r",stdin);
//	freopen("x1.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		scanf("%s",s + 1);
		int n = strlen(s + 1);
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= 14;j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 14;j++){
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				if(s[i] == s1[j - 1]){
					dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << n + 14 - dp[n][14] * 2 << endl;
	}
	return 0;
}
