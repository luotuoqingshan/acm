#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int dp[105][105][1005];
int c,g,n;
char str[20];
int t[105],p[105],s[105];
int main(){
	cin >> g >> c >> n;
	for(int i = 1;i <= n;i++){
		scanf("%s",str);
		if(str[0] == 'g') t[i] = 0;
	   	else if(str[0] == 'h') t[i] = 1;
		else t[i] = 2;	
		scanf("%d%d",&s[i],&p[i]);
	}	
	memset(dp,200,sizeof(dp));	
	dp[0][c][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= c;j++){
			for(int k = 0;k <= 1000;k++){
				if(dp[i - 1][j][k] < 0) continue;
				dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k]);
				if(t[i] == 0){
					if(k >= p[i]){
						dp[i][j][k - p[i]] = max(dp[i][j][k - p[i]],dp[i - 1][j][k] + 1);
					}else{
						if(j > 0){
							int add = (g - p[i] + s[i] - 1) / s[i];
							add = add * s[i];
							if(k + add <= 1000){
								dp[i][j - 1][k + add] = max(dp[i][j - 1][k + add],dp[i - 1][j][k] + 1);
							}
						}
					}
				}else{
					if(k >= p[i]){
						dp[i][j][k - p[i]] = max(dp[i][j][k - p[i]],dp[i - 1][j][k] + 1);
					}
					if(j > 0){
						int add;
						if(t[i] == 1){
							int a = (g - p[i] + s[i] - 1) / s[i];
							int b = (g - p[i]) / s[i];
							if(s[i] * a - (g - p[i]) > (g - p[i]) - b * s[i]){
								add = b * s[i];
							}else{
								add = a * s[i];
							}	
						}else{
							add = (g - p[i]) / s[i];
							add = add * s[i];
						}
							if(k + add <= 1000){
								dp[i][j - 1][k + add] = max(dp[i][j - 1][k + add],dp[i - 1][j][k] + 1);
							}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int j = 0;j <= c;j++){
		for(int k = 0;k <= 1000;k++){
			ans = max(ans,dp[n][j][k]);
		}
	}
	cout << ans << endl;
	return 0;
}
