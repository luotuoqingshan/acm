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

typedef double db;

const db EPS = 1e-8;

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
	bool operator == (P p) const{
		return cmp(x,p.x) == 0 && cmp(y,p.y) == 0;
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

struct L{ //ps[0] -> ps[1]
	P ps[2];
	P& operator[](int i) { return ps[i]; }
	P dir() { return ps[1] - ps[0]; }//直线的方向向量
 	bool include(P p) { return sign((ps[1] - ps[0]).det(p - ps[0])) > 0; }//是否在左边（半平面交的时候有用）
 	L push(){ // push eps outward
 		const double eps = 1e-6;
 		P delta = (ps[1] - ps[0]).rot90().unit() * eps;
 		return {ps[0] - delta, ps[1] - delta};
 	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

P isLL(P p1, P p2, P q1, P q2) {//求两直线交点
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

P isLL(L l1,L l2){ return isLL(l1[0],l1[1],l2[0],l2[1]); }//求两直线交点

int n;

P p[45];
db dis[45];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		p[i].read();
	}
	int ans = n;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				for(int l = k + 1;l <= n;l++){
					P p1 = (p[i] + p[j]) / 2;
					P p2 = (p[k] + p[l]) / 2;
					L l1,l2;
					l1[0] = p1;l1[1] = p1 + (p[i] - p[j]).rot90();	
					l2[0] = p2;l2[1] = p2 + (p[k] - p[l]).rot90();
					P p3;
					if(sign((p[i] - p[j]).det(p[k] - p[l])) == 0){
						if(sign((l1[0] - l2[0]).det(l1[0] - l2[1])) == 0){
							p3 = p1;	
						}else continue;
					}
					else  p3 = isLL(l1,l2);
					for(int m = 1;m <= n;m++){
						dis[m] = (p3 - p[m]).abs2();	
					}
					sort(dis + 1,dis + 1 + n);
					int ret = 0;
					for(int L = 1,R = 1;L <= n;L = R + 1,R = L){
						while(R < n && cmp(dis[R + 1],dis[L]) == 0) R++;
						ret++;	
					}
					ans = min(ans,ret);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
