#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s,s1,s2;
int dp[55][20];
int main(){
s1 = "AKIHABARA";
s2 = "KIHBR";
	cin >> s;	
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= s.length();i++){
		for(int j = 1;j <= s1.length();j++){
			dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
			if(s[i - 1] == s1[j - 1]){
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
			}
		}
	}
	if(dp[s.length()][s1.length()] != s.length())	{
		printf("NO\n");
		return 0;
	}
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= s.length();i++){
		for(int j = 1;j <= s2.length();j++){
			dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
			if(s[i - 1] == s2[j - 1]){
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
			}
		}
	}
	if(dp[s.length()][s2.length()] != s2.length()){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");	
	return 0;
}
