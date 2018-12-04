#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 2e5 + 5;
int n;
int t[maxn],x[maxn],y[maxn],l[maxn * 2];

set<int> s[maxn << 3];

#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r

inline void insert(int o,int l,int r,int ql,int qr,int id){
	if(ql <= l && r <= qr){
		s[o].insert(id);
		return;
	}
	int mid = (l + r) / 2;
	if(ql <= mid) insert(lson,ql,qr,id);
	if(qr > mid) insert(rson,ql,qr,id);
}

inline void erase(int o,int l,int r,int ql,int qr,int id){
	if(ql <= l && r <= qr){
		s[o].erase(id);
		return;
	}
	int mid = (l + r) / 2;
	if(ql <= mid)
		erase(lson,ql,qr,id);
	if(qr > mid)
		erase(rson,ql,qr,id);
}

inline int query(int o,int l,int r,int p,int v){
	for(auto i : s[o]){
		if(1LL * (x[v] - x[i]) * (x[v] - x[i]) + 1LL * (y[v] - y[i]) * (y[v] - y[i]) < 1LL * y[i] * y[i])
			return i;
	}
	if(l == r) return 0;
	int mid = (l + r) / 2;
	if(p <= mid) return query(lson,p,v);
	else return query(rson,p,v);
}

int main(){
	cin >> n;
	int m = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		if(t[i] == 1)	{l[++m] = x[i] - y[i];l[++m] = x[i] + y[i];}
		else l[++m] = x[i];
	}	
	sort(l + 1,l + 1 + m); m = unique(l + 1,l + 1 + m) - l - 1;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(t[i] == 1){
			int L = lower_bound(l + 1,l + 1 + m,x[i] - y[i]) - l;
			int R = lower_bound(l + 1,l + 1 + m,x[i] + y[i]) - l;
			insert(1,1,m,L,R,i);	
		}else if(ans = query(1,1,m,lower_bound(l + 1,l + 1 + m,x[i]) - l,i)){
			int L = lower_bound(l + 1,l + 1 + m,x[ans] - y[ans]) - l;
			int R = lower_bound(l + 1,l + 1 + m,x[ans] + y[ans]) - l;
			erase(1,1,m,L,R,ans);
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
