#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef int db;

inline int sign(db a){
	return a < 0 ? -1 : a > 0;
}

inline int cmp(db a,db b){
	return sign(a - b);
}

struct P{
	db x,y;
	P(){
	}
	P(db _x,db _y):x(_x),y(_y){}
	void read(){
		cin >> x >> y;
	}
};


struct L{
	P ps[2];
	P & operator[](int i){return ps[i];}
};

#define cross(p1,p2,p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))


bool intersect(db l1,db r1,db l2,db r2){
	if(l1 > r1) swap(l1,r1);
	if(l2 > r2) swap(l2,r2);
	return !(cmp(r1,l2) == -1 || cmp(r2,l1) == -1);
}

bool isSS(P p1,P p2,P q1,P q2){
	return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1) * crossOp(q1,q2,p2) <= 0;
}

bool isMiddle(db a,db m,db b){
	return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}

bool isMiddle(P a,P m,P b){
	return isMiddle(a.x,m.x,b.x) && isMiddle(a.y,m.y,b.y);
}
bool onSeg(P p1,P p2,P q){
	return crossOp(p1,p2,q) == 0 && isMiddle(p1,q,p2);
}

const int maxn = 1005;

int w,n;
P a[maxn];
int s[maxn];
P p[maxn];
L l[maxn];
int col[maxn];
vector<int> G[maxn];
bool dfs(int u){
	bool flag = true;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(col[v] == -1){
			col[v] = col[u] ^ 1;
			flag &= dfs(v);
		}else{
			if((col[v] ^ col[u]) == 0) return false;
		}
	}
	return flag;
}
int main(){
//	cout << isSS(P(0,0),P(5,0),P(3,0),P(10,0)) << endl;
//	cout << isSS(P(0,0),P(5,0),P(3,0)
	cin >> w >> n;
	for(int i = 1;i <= w;i++){
		a[i].read();	
	}	
	for(int i = 1;i <= n;i++){
		scanf("%d",&s[i]);
		p[i].read();
		l[i][0] = a[s[i]];
		l[i][1] = p[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(s[i] == s[j]) continue;
			if(isSS(l[i][0],l[i][1],l[j][0],l[j][1])){
				if(!onSeg(l[i][0],l[i][1],l[j][0]) && !onSeg(l[j][0],l[j][1],l[i][0])){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
	}
	memset(col,-1,sizeof(col));
	bool flag = true;
	for(int i = 1;i <= n && flag;i++){
		if(col[i] == -1){
			col[i] = 0;
			flag &= dfs(i);
		}
	}
	if(flag) printf("possible\n");
	else printf("impossible\n");
	return 0;
}
