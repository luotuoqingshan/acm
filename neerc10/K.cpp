#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10000 + 5;

int n,m;
int mx;
int deg[maxn];
int a[maxn],b[maxn];
int col[maxn];
int vis[maxn];
vector<int> G[maxn];
void dfs(int u){
	for(auto v : G[u]){
		if(col[v] > 0) vis[col[v]] = u;
	}	
	for(int i = 1;i <= mx;i++){
		if(vis[i] != u){
			col[u] = i;
			break;
		}
	}
	for(auto v : G[u]){
		if(col[v] == 0) dfs(v);
	}
}

int main(){
	//freopen("kgraph.in","r",stdin);
	//freopen("kgraph.out","w",stdout);
	cin >> n >> m;
	memset(deg,0,sizeof(deg));
	memset(col,0,sizeof(col));
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= m;i++){
		scanf("%d%d",a + i,b + i);	
		deg[a[i]]++,deg[b[i]]++;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	mx = (*max_element(deg + 1,deg + 1 + n)) | 1;
	dfs(1);
	cout << mx << endl;
	for(int i = 1;i <= n;i++){
		printf("%d\n",col[i]);
	}
	return 0;
}
