#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 2005;
vector<LL> a[maxn];
vector<int> G[maxn];

int n;
int p[maxn];
int sz[maxn];

LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

int b[maxn],tot;
int c[maxn];
void dfs(int u){
	a[u].clear();
	sz[u] = 1;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		dfs(v);
		sz[u] += sz[v];
	}
	a[u].push_back(qpow(2,sz[u] - 1));
	for(int i = 0;;i++){
		tot = 0;
		int cnt = 0;
		for(int j = 0;j < G[u].size();j++){
			int v = G[u][j];
			if(a[v].size() > i){
				b[++tot] = a[v][i];
				c[tot] = (qpow(2,sz[v]) - b[tot] + mod) % mod;
				cnt++;
			}else{
				b[++tot] = 0;
				c[tot] = qpow(2,sz[v]);
			}
		}
		if(cnt == 0) break;
		LL all = 2;
		for(int j = 1;j <= tot;j++){
			all = all * c[j] % mod;
		}
		LL ans = 0;
		for(int j = 1;j <= tot;j++){
			LL tmp = all;
			tmp = tmp * qpow(c[j],mod - 2) % mod;
			ans = (ans + tmp * b[j]  % mod) % mod;
		}
		a[u].push_back(ans);
	}	
	/*cout << u << endl;
	for(int i = 0;i < a[u].size();i++){
		cout << i << " " << a[u][i] << " ";
	}
	cout << endl;*/
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int p;
		scanf("%d",&p);
		G[p].push_back(i);
	}
	dfs(0);
	long long ans = 0;
	for(int i = 0;i < a[0].size();i++){
		ans = (ans + a[0][i]) % mod;
	}
	cout << ans << endl;
	return 0;
}

