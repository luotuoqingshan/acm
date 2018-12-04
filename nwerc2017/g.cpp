#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef double db;

const db EPS = 1e-8;
const int maxn = 1005;
const db PI = acos(-1);
inline int sign(db a){
	return a < -EPS ? -1 : a > EPS;
}

inline int cmp(db a,db b){
	return sign(a - b);
}

struct P{
	db x,y;
	P(){}
	P(db _x,db _y):x(_x),y(_y){}
	P operator + (P p){return P(x + p.x,y + p.y);}
	P operator - (P p){return P(x - p.x,y - p.y);}
	db det(P p){ return x * p.y - y * p.x;}
	P rot90(){return P(-y,x);}
	db abs2(){return x * x + y * y;}
	db abs(){return sqrt(abs2());}
	void read(){
		scanf("%lf%lf",&x,&y);
	}
}p[maxn];;

struct L{
	P ps[2];
	P& operator[](int i){return ps[i];}
	db distTo(P p){
		return fabs((ps[1] - ps[0]).det(p - ps[0])) / (ps[1] - ps[0]).abs();
	}
}L[10][10];

db b[10][10];

P a[10][10];

int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		p[i].read();
	}
	for(int i = 3;i <= 8;i++){
		for(int j = 0;j <= i;j++){
			b[i][j] = j * 2 * PI / i;
			a[i][j] = P(cos(b[i][j]),sin(b[i][j]));
		}
		for(int j = 0;j < i;j++){
			L[i][j][0] = P(0,0);
			L[i][j][1] = a[i][j + 1] - a[i][j];
		}
	}
	db ans = 0;
	int id = 0;
	for(int i = 3;i <= 8;i++){
		db mi = 1e9,mx = 0;
		for(int j = 1;j <= n;j++){
			db rad = atan2(p[j].y,p[j].x);
			if(sign(rad) < 0) rad += 2 * PI;
			for(int k = 0;k < i;k++){
				if(cmp(rad,b[i][k]) >= 0 && cmp(rad,b[i][k + 1]) < 0){
					db dis = L[i][k].distTo(p[j]);
					mi = min(dis,mi);
					mx = max(dis,mx);
				}
			}
		}
		if(cmp(mi,ans * mx) > 0){
			ans = mi / mx;
			id = i;
		}	
	}
	printf("%d %.10lf\n",id,ans * ans);
	return 0;
}
