#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 505;

int n,m;
int a[maxn][maxn];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {1,0,-1,-1,-1,0,1,1};
int fa[maxn * maxn];
int sz[maxn * maxn];

int id(int x,int y){
	return (x - 1) * m + y;
}


int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

struct Point{
	int x,y,h;
	Point(int x = 0,int y = 0,int h = 0):x(x),y(y),h(h){}
	bool operator < (const & rhs) const{
		return h < rhs.h;
	}
}p[maxn * maxn];

void merge(int x,int y){
	int fx = Find(x);
	int fy = Find(y);
	if(fx == fy) continue;
	fa[fy] = fx;
	sz[fx] += sz[fy];	
}
int sx,sy;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&a[i][j]);
			p[id(i,j)] = Point(i,j,a[i][j]);
		}
	}
	cin >> sx >> sy;
	sort(p + 1,p + 1 + n * m);
	for(int i = 1;i <= n * m;i++){
		fa[i] = i;
		sz[i] = 1;
	}
	long long ans = 0;
	int i;
	for(i = 1;i < n * m;i++){
		if(p[i + 1].h >= 0) break;	
		int now = sz[Find(id(sx,sy))];
		if(i > 1){
			
		}
		for(int j = 0;j < 8;j++){
			int nx = p[i].x + dx[j];
			int ny = p[i].y + dy[j];
			merge(id(p[i].x,p[i].y),id(nx,ny));
		}	
	}
	cout << ans << endl;
	return 0;
}
