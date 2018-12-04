#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 55;
vector<int> G[maxn];
int dis[maxn];
int N,x;

void bfs(int u){
	memset(dis,0x3f,sizeof(dis));
	dis[u] = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int p = q.front();q.pop();
		for(int i = 0;i < G[p].size();i++){
			int v = G[p][i];
			if(dis[v] > dis[p] + 1){
				dis[v] = dis[p] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	cin >> N >> x;
	for(int i = 1;i <= N;i++){
		int d;
		scanf("%d",&d);
		for(int j = 1;j <= d;j++){
			int v;
			scanf("%d",&v);
			G[i].push_back(v);
		}
	}	
	bfs(x);
	vector<int> ans(0);
	for(int i = 1;i <= N;i++){
		if(dis[i] == 2){
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(),ans.end());
	for(int i = 0;i < ans.size();i++){
		printf("%d%c\n",ans[i],i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
