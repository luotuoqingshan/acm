#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e7 + 50;
int n;
int a[maxn];
bool vis[maxn];
int pre[maxn];
int l[maxn / 10],r[maxn / 10];
vector<int> g[maxn];
void init(){
	vis[1] = 1;
	for(int i = 2;i <= 10000000;i++){
		if(!vis[i]){
		    g[i].push_back(i);
			for(int j = i;j <= 10000000;j += i){
				vis[j] = 1;
				g[j].push_back(i);
			}
		}
	}
}

int fa[maxn / 10];
int lson[maxn / 10];
int rson[maxn / 10];

void work(){
	int now = 1;
	fa[1] = 0;
	lson[1] = 0;
	rson[1] = 0;
	for(int i = 2;i <= n;i++){
	}
}

int main(){
	init();
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}	
	for(int i = 1;i <= n;i++){
		l[i] = 1,r[i] = n;
		for(int j = 0;j < g[a[i]].size();j++){
			l[i] = max(l[i],pre[g[a[i]][j]] + 1);
			pre[g[a[i]][j]] = i;
		}	
	}
	for(int i = 1;i <= 10000000;i++){
		pre[i] = n + 1;
	}	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < g[a[i]].size();j++){
			r[i] = min(r[i],pre[g[a[i]][j]] - 1);
			pre[g[a[i]][j]] = i;
		}
	}
	return 0;
}
