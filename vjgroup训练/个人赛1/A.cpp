#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;

struct element{
	int a,b;
	bool operator < (const element & rhs) const{
		return a < rhs.a;
	}
}s[maxn];

int maxv[maxn << 2];

#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r

void pushup(int o){
	maxv[o] = max(maxv[o * 2],maxv[o * 2 + 1]);
}

void build(int o,int l,int r){
	if(l == r){
		maxv[o] = s[l].b;
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(o);
}

void update(int o,int l,int r,int p){
	if(l == r){
		maxv[o] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if(p <= mid) update(lson,p);
	else update(rson,p);
	pushup(o);
}

int n;


int main(){
	int T;
	int cas = 0;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d%d",&s[i].a,&s[i].b);
		}
		sort(s + 1,s + 1 + n);
		build(1,1,n);
		int ans = 2e9 + 5;
		for(int i = 1;i <= n;i++){
			update(1,1,n,i);
			ans = min(ans,s[i].a + maxv[1]);
		}
		printf("Case %d: ",++cas);
		cout << ans << endl;
	}
	return 0;
}
