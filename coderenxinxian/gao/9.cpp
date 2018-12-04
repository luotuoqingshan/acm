#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int n,m;

struct S{
	int type,x,l,r,m;
	S(int type = 0,int x = 0,int l = 0,int r = 0,int m = 0):type(type),x(x),l(l),r(r),m(m)
	{}
	bool operator < (const S & rhs) const{
		if(x != rhs.x) return x < rhs.x;
		return type < rhs.type;
	}
}p[maxn * 3];

int ans[maxn];

int c[maxn];

void add(int x,int v){
	for(int i = x;i < maxn;i += i & -i){
		c[i] += v;
	}
}

int sum(int x){
	int ret = 0;
	for(int i = x;i > 0;i -= i & -i){
		ret += c[i];
	}
	return ret;
}

int Sum(int l,int r){
	return sum(r) - sum(l - 1);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			p[i] = S(0,x,y);
		}
		for(int i = 1;i <= m;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			p[i * 2 - 1 + n] = S(1,x1 - 1,y1,y2,-i);
			p[i * 2 + n] = S(1,x2,y1,y2,i);
		}
		sort(p + 1,p + 1 + n + 2 * m);
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(int i = 1;i <= 2 * m + n;i++){
			if(p[i].type == 0){
				add(p[i].l,1);
			}else{
				if(p[i].m > 0){
					ans[p[i].m] += Sum(p[i].l,p[i].r);
				}else{
					ans[-p[i].m] -= Sum(p[i].l,p[i].r);
				}
			}
		}
		for(int i = 1;i <= m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
/*
1
10 5
0 2
3 0
6 0
0 15
2 2
0 16
15 4
11 14
5 2
0 4
4 0 17 12
12 4 16 16
12 0 18 18
4 0 14 16
0 10 17 12
 */
