#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;

const int maxn = 5005;
vector<int> G[maxn];

void add(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

int dp[maxn];
int dep[maxn];
int par[maxn];
int dfs(int u,int fa,int depth){
	dep[u] = depth;
	dp[u] = 0;
	par[u] = fa;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(v == fa) continue;
		dp[u] = max(dp[u],dfs(v,u,depth + 1) + 1);
	}
	return dp[u];
}
int main(){
	//freopen("a2.in","r",stdin);
	//freopen("a2.out","w",stdout);
	cin >> n;
	for(int i = 2;i <= n;i++){
		int fa;
		scanf("%d",&fa);
		add(i,fa);
	}
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u == v){
			printf("0\n");
		}else{
			dfs(u,-1,0);
			int ans = 0;
			int now = v;
			while(dep[v] - dep[now] < dep[now] - dep[u]){
				ans = max(ans,dp[now] + dep[now] - dep[u]);
				now = par[now];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
