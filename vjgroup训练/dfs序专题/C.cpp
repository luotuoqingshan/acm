#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int T;



const int maxn = 200000 + 10;

int n,m;

int v[maxn];
int L[maxn],R[maxn];
int tid[maxn];
long long d[maxn];
vector<int> G[maxn];
int tot;
void dfs(int u,int fa){
	L[u] = ++tot;
	tid[tot] = u;
	for(int i = 0;i < G[u].size();i++){
		int to = G[u][i];
		if(to == fa) continue;
		d[to] = d[u] + v[to];
		dfs(to,u);
	}
	R[u] = ++tot;
	tid[tot] = u;
}


struct segmenttree{
	long long maxv[maxn << 2],lazy[maxn << 2];
	void pushup(int o){
		maxv[o] = max(maxv[o << 1],maxv[o << 1 | 1]);
	}
	void pushdown(int o){
		lazy[o << 1] += lazy[o];
		lazy[o << 1 | 1] += lazy[o];
		maxv[o << 1] += lazy[o];
		maxv[o << 1 | 1] += lazy[o];
		lazy[o] = 0;
	}
	void build(int o,int l,int r){
		if(l == r){
			lazy[o] = 0;
			maxv[o] = d[tid[l]];
			return;
		}
		lazy[o] = 0;
		int mid = (l + r) / 2;
		build(o * 2,l,mid);
		build(o * 2 + 1,mid + 1,r);
		pushup(o);
	}
	
	void update(int o,int l,int r,int ql,int qr,long long v){
		if(ql <= l && r <= qr){
			maxv[o] += v;
			lazy[o] += v;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if(ql <= mid) update(o * 2,l,mid,ql,qr,v);
		if(qr > mid) update(o * 2 + 1,mid + 1,r,ql,qr,v);
		pushup(o);
	}
	
	long long query(int o,int l,int r,int ql,int qr){
		if(ql <= l && r <= qr){
			return maxv[o];
		}
		int mid = (l + r) / 2;
		pushdown(o);
		long long ans = -1e18;
		if(ql <= mid) ans = max(ans,query(o * 2,l,mid,ql,qr));
		if(qr > mid) ans = max(ans,query(o * 2 + 1,mid + 1,r,ql,qr));
		pushup(o);
		return ans;
	}
}Tree;
	

int main(){
	cin >> T;
	int cas = 0;
	while(T--){
		cin >> n >> m;
		tot = 0;
		for(int i = 0;i < n;i++) G[i].clear();
		for(int i = 1;i < n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(int i = 0;i < n;i++){
			scanf("%d",v + i);
		}
		d[0] = v[0];
		dfs(0,-1);
		Tree.build(1,1,2 * n);
		printf("Case #%d:\n",++cas);
		for(int i = 1;i <= m;i++){
			int op;
			scanf("%d",&op);
			if(op == 0) {
				int x,y;
				scanf("%d%d",&x,&y);
				long long change = y - v[x];
				Tree.update(1,1,2 * n,L[x],R[x],change);
				v[x] = y;
			}else{
				int x;
				scanf("%d",&x);
				long long ans = Tree.query(1,1,2 * n,L[x],R[x]);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
