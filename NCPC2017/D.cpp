#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
int a[maxn];
const int maxm = (1 << 20) + 5;
vector<int> G[maxm];
bool vis[maxm];
int dis[maxm];
char str[25];

void bfs(){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(vis[a[i]]) continue;
		q.push(a[i]);
		dis[a[i]] = 0;
		vis[a[i]] = 1;
	}
	while(!q.empty()){
		int p = q.front();q.pop();
		for(int i = 0;i < k;i++){
			int to = p ^ (1 << i);
			if(vis[to]) continue;
			q.push(to);
			dis[to] = dis[p] + 1;
			vis[to] = 1;
		}	
	}
	int ans = -1,id = 0;
	for(int i = 0;i < (1 << k);i++){
		if(dis[i] > ans){
			ans = dis[i];
			id = i;
		}	
	}
	for(int i = 0;i < k;i++){
		str[k - 1 - i] = id % 2 + '0';
		id /= 2;
	}
	str[k] = 0;
	printf("%s",str);	
}


int main(){
	while(cin >> n >> k){
		for(int i = 1;i <= n;i++){
			scanf("%s",str);
			int now = 0;
			for(int j = 0;j < k;j++){
				now = now * 2 + str[j] - '0';
			}
			a[i] = now;
		}
		bfs();
	}
	return 0;
}
