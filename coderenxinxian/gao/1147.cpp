#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn][2];
bool vis[maxn][maxn][2];
int n,k;
char s[maxn][maxn];
int sx,sy;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<int,piii> piiii;
priority_queue<piiii,vector<piiii>,greater<piiii>> pq;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
bool in(int x,int y){
	return x > 0 && x <= n && y > 0 && y <= n;
}
void solve(){
	memset(d,INF,sizeof(d));
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(s[i][j] == 'S'){
				sx = i,sy = j;
				break;
			}
		}
	}	
	d[sx][sy][0] = 0;
	pq.push(make_pair(0,make_pair(0,make_pair(sx,sy))));
	while(!pq.empty()){
		piiii p = pq.top();pq.pop();
		int nx = p.second.second.first;
		int ny = p.second.second.second;
		int t = p.second.first;
		if(vis[nx][ny][t]) continue;
		vis[nx][ny][t] = 1;
		if(s[nx][ny] == 'X') continue;
		for(int i = 0;i < 4;i++){
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if(in(tx,ty) && s[tx][ty] != 'O'){
				int tt = t | (s[tx][ty] == 'C');
				if(t == 0){
					if(d[tx][ty][tt] > d[nx][ny][t] + 2){
						d[tx][ty][tt] = d[nx][ny][t] + 2;
						pq.push(make_pair(d[tx][ty][tt],make_pair(tt,make_pair(tx,ty))));
					}
				}else{
					if(d[tx][ty][tt] > d[nx][ny][t] + 1){
						d[tx][ty][tt] = d[nx][ny][t] + 1;
						pq.push(make_pair(d[tx][ty][tt],make_pair(tt,make_pair(tx,ty))));
					}
				}
			}
		}	
	}
	int ans = INF;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(s[i][j] == 'X' && min(d[i][j][0],d[i][j][1]) <= k) ans = min(ans,min(d[i][j][0],d[i][j][1]));
		}
	}
	if(ans != INF) printf("YES\n%d\n",ans);
	else printf("NO\n");
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			scanf("%s",s[i] + 1);
		}	
		solve();
	}
	return 0;
}

