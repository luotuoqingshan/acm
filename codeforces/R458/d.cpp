#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

const int maxn = 5e5 + 5;

int a[maxn];
int g[maxn << 2];

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}

void pushup(int o){
	g[o] = gcd(g[o << 1],g[(o << 1) | 1]);
}

#define lson o << 1,l,mid
#define rson (o << 1)|1,mid + 1,r

void build(int o,int l,int r){
	if(l == r){
		g[o] = a[l];	
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(o);
}

int oo,ll,rr;

int query(int o,int l,int r,int ql,int qr,int x){
	if(ql <= l && r <= qr){
		if(g[o] % x){
			oo = o,ll = l,rr = r;
		}
		return g[o];
	}
	int mid = (l + r) / 2;
	if(qr <= mid) return query(lson,ql,qr,x);
	if(ql > mid) return query(rson,ql,qr,x);
	return gcd(query(lson,ql,qr,x),query(rson,ql,qr,x));
}

void update(int o,int l,int r,int p,int v){
	if(l == r){
		g[o] = v;
		return;
	}
	int mid = (l + r) / 2;
	if(p <= mid) update(lson,p,v);
	else update(rson,p,v);
	pushup(o);
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	for(int i = 1;i <= q;i++){
		int type;
		scanf("%d",&type);
		if(type == 1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			oo = -1;
			if(query(1,1,n,l,r,x) % x == 0){
				printf("YES\n");
				continue;
			}
			if(l == r && oo == -1){
				puts("YES");
				continue;
			}
			while(ll < rr){
				int mid = (ll + rr) / 2;
				if(g[oo * 2] % x == 0){
					oo = oo * 2 + 1;
					ll = mid + 1;
				}else{
					oo = oo * 2;
					rr = mid;
				}
			}
			int pos = ll;
			if(pos == r) puts("YES");
			else{
				if(query(1,1,n,pos + 1,r,x) % x == 0){
					puts("YES");
				}else puts("NO");
			}
		}else{
			int p,v;
			scanf("%d%d",&p,&v);
			update(1,1,n,p,v);
		}
	}
	return 0;
}
