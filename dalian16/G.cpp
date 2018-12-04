#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


const int maxn = 50000 + 5;
vector<int> nodes;
int size[maxn],maxbranch[maxn];
vector<int> G[maxn];
int del[maxn];
long long num[maxn];
int n,m,k;
int col[maxn];
int pre[15];
int getsize(int u,int fa){
	nodes.push_back(u);
	size[u] = 1;
	maxbranch[u] = 0;
	for(auto v : G[u]){
		if(v == fa || del[v]) continue;
		size[u] += getsize(v,u);
		maxbranch[u] = max(maxbranch[u],size[v]);
	}
	return size[u];
}

int getroot(int u){
	nodes.clear();
	getsize(u,-1);
	int rt = u;
	for(auto v : nodes){
		maxbranch[v] = max(maxbranch[v],size[u] - size[v]);
		if(maxbranch[v] < maxbranch[rt]) rt = v;
	}
	return rt;
}

long long ans;
int a[maxn],tot;
void getdeep(int u,int fa,int d){
	d |= pre[col[u]];
	num[d]++;
	a[++tot] = d;
	for(auto v : G[u]){
		if(v == fa || del[v]) continue;
		getdeep(v,u,d);	
	}
}

long long cal(int u,int d){
	memset(num,0,sizeof(long long) * m);
	tot = 0;
	getdeep(u,-1,d);
	long long ret = 0;
	for(int i = 1;i <= tot;i++){
		for(int j = a[i];j;j = (j - 1) & a[i]){
			ret += num[j ^ (m - 1)];
		}
		ret += num[m - 1];
	}
	return ret;
}

void solve(int u){
	int rt = 0;
	rt = getroot(u);
	del[u] = 1;
	ans += cal(rt,0);
	for(auto v : G[u]){
		if(del[v]) continue;
		ans -= cal(v,pre[col[rt]]);
		solve(v);
	}
}


int main(){
	for(int i = 0;i < 15;i++){
		pre[i] = (1 << i);
	}
	while(scanf("%d%d",&n,&k) != EOF){
		m = (1 << k);
		ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&col[i]);
			col[i]--;
			G[i].clear();
			del[i] = 0;
		}
		for(int i = 1;i < n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		solve(1);
		printf("%lld\n",ans);
	}
	return 0;
}
