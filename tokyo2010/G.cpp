#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
priority_queue<piii,vector<piii>,greater<piii> >pq;
int n,m,c;
const int maxn = 105;
vector<pii> G[maxn];
bool vis[maxn][maxn * 10];
const int INF = 0x3f3f3f3f;
int d[maxn][maxn * 10];

void solve(){
	memset(d,INF,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[1][0] = 0;
	pq.push(make_pair(0,make_pair(1,0)));
	while(!pq.empty()){
		piii p = pq.top();pq.pop();
		int u = p.second.first;
		int t = p.second.second;
		if(vis[u][t]) continue;
		vis[u][t] = true;
		for(int i = 0;i < G[u].size();i++){
			int v = G[u][i].first;
			int cost = G[u][i].second;
			if(d[v][t] > d[u][t] + cost){
				d[v][t] = d[u][t] + cost;
				pq.push(make_pair(d[v][t],make_pair(v,t)));
			}
			if(d[v][t + 1] > d[u][t]){
				d[v][t + 1] = d[u][t];
				pq.push(make_pair(d[v][t + 1],make_pair(v,t + 1)));
			}
		}
	}	
}
int main(){
	while(cin >> n >> m >> c){
		if(n == 0) break;
		for(int i = 1;i <= n;i++)
			G[i].clear();
		while(!pq.empty()) pq.pop();
		for(int i = 1;i <= m;i++){
			int f,t,w;
			scanf("%d%d%d",&f,&t,&w);
			G[f].push_back(make_pair(t,w));	
		}	
		solve();
		for(int i = 0;i <= m;i++){
			if(d[n][i] <= c){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

