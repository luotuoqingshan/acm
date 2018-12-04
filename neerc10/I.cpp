#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int maxn = 100000 + 5;
queue<int> q;
vector<pair<int,int> > G[maxn];
int dis[maxn];
bool vis[maxn];
int n,m;
void bfs(int s){
	vis[s] = 1;
	q.push(s);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s] = 0;
	while(!q.empty()){
		int p = q.front();q.pop();
		vis[p] = 0;
		for(auto v : G[p]){
			int to = v.first;
			int col = v.second;
			if(dis[to] > dis[p] + 1){
				dis[to] = dis[p] + 1;
				if(!vis[to]){
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}	
}

int ans[maxn],col[maxn];

void work(){
	q.push(1);
	memset(ans,0x3f3f3f3f,sizeof(ans));
	memset(col,0x3f3f3f3f,sizeof(col));
	memset(vis,0,sizeof(vis));
	col[1] = ans[dis[1]] = 0;
	vis[1] = 1;
	while(!q.empty()){
		int p = q.front();q.pop();
		vis[p] = 0;
		if(col[p] != ans[dis[p]]) continue;
		for(auto v : G[p]){
			int to = v.first;int c = v.second;
			if(dis[to] != dis[p] - 1) continue;
			col[to] = min(col[to],c); ans[dis[to]] = min(ans[dis[to]],c);
			if(!vis[to]) q.push(to),vis[to] = 1;
		}
	}	
	for(int i = dis[1] - 1;i >= 0;i--){
		printf("%d%c",ans[i],i == 0 ? '\n' : ' ');
	}
}

int main(){
	freopen("ideal.in","r",stdin);
	freopen("ideal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		if(u == v) continue;
		G[u].push_back(make_pair(v,c));
		G[v].push_back(make_pair(u,c));
	}
	bfs(n);
	cout << dis[1] << endl;
	work();
	return 0;
}
