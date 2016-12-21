#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;

int in[maxn];
int com[2005];
int p[2005];
int l[2005];
int r[2005];

int n,m;
int dp[2][maxn];


int main(){
	cin >> m >> n;
	for(int i = 1;i <= m;i++){
		scanf("%d",&in[i]);
	}
	sort(in + 1,in + 1 + m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&com[i]); 
	}
	sort(com + 1,com + 1 + n);
	for(int i = 1;i <= n;i++){
		p[i] = lower_bound(in + 1,in + 1 + m,com[i]) - in;
		l[i] = max(1,p[i] - n);
		r[i] = min(p[i] + n,m);
		//cout << l[i] << " " << r[i] << endl;
	}
	memset(dp,INF,sizeof(dp));
	for(int i = 0;i <= m;i++)
		dp[0][i] = 0;
	int now = 0;
	int s1 = 1,e1 = m,s2,e2;
	for(int i = 1;i <= n;i++){
		now = now ^ 1;
		s2 = l[i],e2 = r[i];
		dp[now][s2 - 1] = INF;
		for(int j= s2;j <= e2;j++){
			if(j >= s1 && j <= e1)
				dp[now][j] = min(dp[now ^ 1][j - 1] + abs(com[i] - in[j]),dp[now][j - 1]);
			else
				dp[now][j] = min(dp[now ^ 1][e1] + abs(com[i] - in[j]),dp[now][j - 1]);
		}
		s1 = l[i],e1 = r[i];
		/*for(int j = 1;j <= m;j++){
			cout << dp[now][j] << " ";
		}*/
	//	cout << endl;
	}
	cout << dp[now][m] << endl;
	return 0;
}
