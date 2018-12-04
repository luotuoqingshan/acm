#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const int maxn = 300000 + 5;

vector<int> G[maxn];

void add(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

int n;
int size[maxn],maxv[maxn];
bool vis[maxn];

void getsize(int u,int fa){
	size[u] = 1;
	maxv[u] = 0;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(v == fa || vis[v]) continue;
		getsize(v,u);
		size[u] += size[v];
		if(size[v] > maxv[u]) maxv[u] = size[v];
	}	
}
int root,MAX;
void dfsroot(int r,int u,int fa){
	if(size[r]  - size[u] > maxv[u]){
		maxv[u] = size[r] - size[u];
	}
	if(maxv[u] < MAX) MAX = maxv[u],root = u;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(v == fa || vis[v]) continue;
		dfsroot(r,v,u);
	}
}

int dfs(int u,int depth){
	MAX = n;
	getsize(u,0);
	dfsroot(u,u,0);
	vis[root] = 1;
	cout << root << endl;
	int now = depth;
	for(int i = 0;i < G[root].size();i++){
		int v = G[root][i];
		if(!vis[v]){
			int tmp = dfs(v,depth + 1);
			now = max(now,tmp);
		}
	}
	return now;
}

int main(){
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	int depth = dfs(1,1);
	cout << depth << endl;
	return 0;
}
