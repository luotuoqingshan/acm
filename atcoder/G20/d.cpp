#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int q;
int a,b,c,d;
const int maxn = 2e3 + 5;
char f[maxn];
int dp[maxn];
void solve(int a,int b,int c,int d){
	memset(f,0,sizeof(f));
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	int len = max((a + b) / (b + 1),(b + a) / (a + 1));	
	//cout << len << endl;
	int L = a + b;
	for(int i = 1;i <= L;i++){
		if(dp[i - 1] == len){
			if(f[i - 1] == 'A'){
				f[i] = 'B';
				b--;
			}else{
				f[i] = 'A';
				a--;
			}
		}else{
			if(a == 0){
				f[i] = 'B';
				b--;
				if(f[i] == f[i - 1]) dp[i] = dp[i - 1] + 1;
				else dp[i] = 1;
				continue;
			}
			if(b == 0){
				f[i] = 'A';
				b--;
				if(f[i] == f[i - 1]) dp[i] = dp[i - 1] + 1;
				else dp[i] = 1;
				continue;
			}
			int aa = a - 1;
			int bb = b;
			if((bb + aa) / (aa + 1) <= len){
				f[i] = 'A';
				a--;
				if(f[i] == f[i - 1]) dp[i] = dp[i - 1] + 1;
				else dp[i] = 1;
			}else{
				f[i] = 'B';
				b--;
				if(f[i] == f[i - 1]) dp[i] = dp[i - 1] + 1;
				else dp[i] = 1;
			}
		}
	}
	for(int i = c;i <= d;i++){
		putchar(f[i]);
	}
	puts("");
}

int main(){
	cin >> q;
	while(q--){
		cin >> a >> b >> c >> d;
		solve(a,b,c,d);
	}
	return 0;
}
