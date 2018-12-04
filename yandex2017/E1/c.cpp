#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 200000 + 5;
int n,m;
vector<int> G[maxn];
bool vis[maxn];
int col[maxn];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u < v) swap(u,v);
		G[u].push_back(v);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < G[i].size();j++){
			int v = G[i][j];
			vis[col[v]] = 1;
		}
		int now = 1;
		while(vis[now])now++;
		col[i] = now;
		for(int j = 0;j < G[i].size();j++){
			int v = G[i][j];
			vis[col[v]] = 0;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		ans = max(ans,col[i]);
	}
	cout << ans << endl;
	for(int i = 1;i <= n;i++){
		printf("%d%c",col[i],i == n ? '\n' : ' ');
	}
	return 0;
}
