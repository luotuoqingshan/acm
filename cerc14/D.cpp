#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1005;
int n;
int x[maxn],y[maxn],r[maxn];
int dep[maxn];
int vis[maxn];
vector<int> G[maxn];

void dfs(int u,int d){
	vis[u] = true;
	dep[u] = d;
	for(auto v : G[u]){
		if(vis[v]) continue;
		dfs(v,d + 1);
	}	
}

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(dep,0,sizeof(dep));
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)
			G[i].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if((r[i] + r[j]) * (r[i] + r[j]) == (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		dfs(1,1);
		for(int i = 1;i <= n;i++){
			if(dep[i] == 0){
				printf("not moving\n");
				continue;
			}
			int g = gcd(r[i],r[1]);
			int p = r[1] / g;
			int q = r[i] / g;
			if(q == 1) printf("%d ",p);
			else printf("%d/%d ",p , q);
			if(dep[i] & 1)
				printf("clockwise\n");
			else printf("counterclockwise\n");
		}
	}
	return 0;
}
