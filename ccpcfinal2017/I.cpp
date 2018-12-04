#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 2e5 + 5;

int T,N,M;
vector<int> G[maxn];
int deg[maxn];
typedef pair<pair<int,int>,int> piii;
map<pair<int,int> ,int> e;
map<int,int> C,P[maxn];
int tot;
piii E[maxn];
bool cir[maxn];
void bfs(){
	queue<int> q;
	for(int i = 1;i <= N;i++){
		if(deg[i] == 1)
			q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : G[u]){
			int v = E[i].first.first ^ E[i].first.second ^ u;
			--deg[v];
			if(deg[v] == 1) q.push(v);
		}
	}
	for(int i = 1;i <= N;i++) cir[i] = (deg[i] == 2);	
}
int main(){
	cin >> T;
	for(int cas = 1;cas <= T;cas++){
		scanf("%d%d",&N,&M);
		for(int i = 1;i <= N;i++){
			deg[i] = 0;cir[i] = 0;
			G[i].clear();
			P[i].clear();
		}
		e.clear(),C.clear();
		tot = 0;
		for(int i = 1;i <= N;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			if(x > y) swap(x,y);
			e[make_pair(x,y)] = i;
			E[i] = make_pair(make_pair(x,y),c);
			++deg[x],++deg[y];
			G[x].push_back(i);G[y].push_back(i);
			P[x][c]++;P[y][c]++;
		}
		bfs();
		for(int i = 1;i <= N;i++){
			int x = E[i].first.first;
			int y = E[i].first.second;
			if(deg[x] == 2 && deg[y] == 2)
				++C[E[i].second];
		}
		tot = -N;
		for(int i = 1;i <= N;i++) tot += P[i].size();
		printf("Case #%d:\n",cas);
		for(int i = 1;i <= M;i++){
			int x,y,c,ans;
			scanf("%d%d%d",&x,&y,&c);
			if(x > y) swap(x,y);
			int j = e[make_pair(x,y)];
			tot -= P[x].size() + P[y].size();
			if(deg[x] == 2 && deg[y] == 2){
				if(--C[E[j].second] == 0){
					C.erase(E[j].second);
				}
			}
			if(--P[x][E[j].second] == 0) P[x].erase(E[j].second);
			if(--P[y][E[j].second] == 0) P[y].erase(E[j].second);
			E[j].second = c;
			++P[x][c],++P[y][c];
			if(deg[x] == 2 && deg[y] == 2)
				++C[c];
			tot += P[x].size() + P[y].size();
			ans = tot;
			if(C.size() == 1) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
