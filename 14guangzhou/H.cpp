#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back

typedef long double db;

const db EPS = 1e-12;

inline int sign(db a) {
	return a < -EPS ? -1 : a > EPS;
}

inline int cmp(db a, db b){//精度比较函数
	return sign(a-b);
}

struct P {//点
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return P(x + p.x, y + p.y); }
	P operator-(P p) { return P(x - p.x, y - p.y); }
	P operator*(db d) { return P(x * d, y * d); }
	P operator/(db d) { return P(x / d, y / d); }
	bool operator<(P p) const {
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
	db dot(P p) { return x * p.x + y * p.y; }//点积
	db det(P p) { return x * p.y - y * p.x; }//叉积
	db distTo(P p) { return (*this-p).abs(); }//距离
	db alpha() { return atan2(y, x); }//求极角
	void read() { cin>>x>>y; }
	db abs() { return sqrt(abs2());}//长度
	db abs2() { return x * x + y * y; }//长度的平方
	P rot90() { return P(-y,x);}//逆时针旋转90度
	P unit() { return *this/abs(); }//单位化
    int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }//极角是否在[0,180)之间
};
db rad(P p1,P p2){ //
	return atan2l(p1.det(p2),p1.dot(p2));
}

vector<P> isCL(P o,db r,P p1,P p2){
	db x = (p1-o).dot(p2-p1), y = (p2-p1).abs2(), d = x * x - y * ((p1-o).abs2() - r*r);
	if(sign(d) < 0) return {};
	d = max(d,0.0); P m = p1 - (p2-p1)*(x/y), dr = (p2-p1)*(sqrt(d)/y);
	return {m-dr,m+dr}; //along dir: p1->p2
}

db areaCT(db r, P p1, P p2){
	vector<P> is = isCL(P(0,0),r,p1,p2);
	if(is.empty()) return r*r*rad(p1,p2)/2;
	bool b1 = cmp(p1.abs2(),r*r) == 1, b2 = cmp(p2.abs2(), r*r) == 1;
	if(b1 && b2){
		if(sign((p1-is[0]).dot(p2-is[0])) <= 0 &&
			sign((p1-is[0]).dot(p2-is[0])) <= 0)
		return r*r*(rad(p1,is[0]) + rad(is[1],p2))/2 + is[0].det(is[1])/2;
		else return r*r*rad(p1,p2)/2;
	}
	if(b1) return (r*r*rad(p1,is[0]) + is[0].det(p2))/2;
	if(b2) return (p1.det(is[1]) + r*r*rad(is[1],p2))/2;
	return p1.det(p2)/2;
}

const db pi = acos(-1.0);

int main(){
	db v0,v1,D,T;
	while(cin >> v0 >> v1 >> D >> T){
		if(T * v0 < D + EPS){
			printf("%.15lf\n",pi * (T * v0) * (T * v0));
			continue;
		}
		db l = 0.0,r = acos(D / (T * v0));
		for(int i = 1;i <= 200;i++){

		}
	}
	return 0;
}