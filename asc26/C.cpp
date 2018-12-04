#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
typedef long long ll;
const int maxn = (1 << 16) + 5;

ll L,R;
ll v[35],w[35];
int m;

pair<ll,pair<ll,ll> > a[maxn];
ll b[maxn];
int tot;

#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r
ll maxv[maxn << 2];
ll st[maxn << 2];

void build(int o,int l,int r){
	if(l == r){
		maxv[o] = a[l].second.first;
		st[o] = a[l].second.second;
		return;
	}		
	int mid = (l + r) / 2;
	build(lson);build(rson);
	if(maxv[o * 2] > maxv[o * 2 + 1]){
		maxv[o] = maxv[o * 2];
		st[o] = st[o * 2];
	}else{
		maxv[o] = maxv[o * 2 + 1];
		st[o] = st[o * 2 + 1];
	}
}

pair<ll,ll> query(int o,int l,int r,int ql,int qr){
	if(qr > ql) return make_pair(0,0);
	if(ql <= l && r <= qr) return make_pair(maxv[o],st[o]);
	int mid = (l + r) / 2;
	pair<ll,ll> ans = make_pair(0,0);
	if(ql <= mid) ans = max(ans,query(lson,ql,qr));
	if(qr > mid) ans = max(ans,query(rson,ql,qr));
	return ans;
}

void init(){
	tot = 0;
	for(int i = 0;i < (1 << m);i++){
		long long sv = 0,sw = 0;
		for(int j = 0;j < m;j++){
			if(i & (1 << j)){
				sv += v[j];
				sw += w[j];
			}
		}
		a[++tot] = make_pair(sw,make_pair(sv,i));
	}	
	sort(a + 1,a + 1 + tot);
	for(int i = 1;i <= tot;i++)
		b[i] = a[i].first;
	build(1,1,tot);
}

int main(){
	while(cin >> n){
		cin >> L >> R;
		for(int i = 0;i < n;i++){
			cin >> w[i] >> v[i];
		}
		m = n / 2;
		init();
		ll ans = 0;
		for(int i = 0;i < (1 << (n - m));i++){
			ll sv = 0,sw = 0;
			for(int j = 0;j < (n - m);j++){
				if(i & (1 << j)){
					sv += v[j + m];
					sw += w[j + m];
				}
			}
			ll tmpL = L - sw,tmpR = R - sw;
			int ql = lower_bound(b + 1,b + 1 + tot,tmpL) - b;
			int qr = upper_bound(b + 1,b + 1 + tot,tmpR) - b;
			qr--;
			ans = max(ans,sv + query(1,1,tot,ql,qr));
		}
		cout << ans << endl;
	}

	return 0;
}
