#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

const int maxn = 2e5 + 5;

vector<int> G[maxn];

typedef long long LL;

struct data{
	LL a,b,c;
	data(LL a = 0,LL b = 0,LL c = 0):a(a),b(b),c(c){}
};

deque<data> dp[maxn];

const LL mod = 1e9 + 7;

LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1){
			ret = ret * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}


int n;
int cnt[maxn];

void pre(int u,int dep){
	cnt[dep]++;
	for(auto v : G[u]){
		pre(v,dep + 1);
	}
}

void solve(int u,int dep){
	deque<data> & now = dp[u];
	for(auto v : G[u]){
		solve(v,dep + 1);
		if(dp[v].size() > now.size())
			swap(now,dp[v]);
	}
	int mx = 0;
	for(auto v : G[u]){
		mx = max(mx,(int) dp[v].size());
		for(int i = 0;i < dp[v].size();i++){
			LL tmpa = (now[i].a * dp[v][i].a) % mod;
			LL tmpb = (now[i].a * dp[v][i].b + now[i].b * dp[v][i].a) % mod;
			LL tmpc = (now[i].b * dp[v][i].b + now[i].c * (dp[v][i].a + dp[v][i].b)) % mod;
			now[i].a = tmpa;
			now[i].b = tmpb;
			now[i].c = tmpc;
		}
	}
	for(int k = 0;k < mx;k++){
		now[k].a = (now[k].a + now[k].c) % mod;
		now[k].c = 0LL;
	}
	now.push_front(data(1LL,1LL,0LL));
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		scanf("%d",&x);
		G[x].push_back(i);
	}	
	pre(0,0);
	solve(0,0);
	LL res = 0;
	for(int i = 0;i < dp[0].size();i++){
		res = (res + dp[0][i].b * qpow(2,n + 1 - cnt[i]) % mod) % mod;
	}
	cout << res << endl;
	return 0;
}

