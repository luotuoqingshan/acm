#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
const int maxn = 10005;
int a[maxn];
vector<int> G[maxn];
bool vis[maxn];

int dfs(int u){
	vis[u] = true;
	int sum = a[u];
	for(auto v : G[u]){
		if(vis[v]) continue;
		sum += dfs(v);
	}
	return sum;
}
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}	
	for(int i = 1;i <= m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag = true;
	for(int i = 0;i < n;i++){
		if(!vis[i]){
			int tmp = dfs(i);
			if(tmp != 0) flag = false;
		}
	}
	if(flag) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}
