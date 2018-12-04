#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

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

bool parallel(L l0, L l1) { return sign( l0.dir().det( l1.dir() ) ) == 0; }//判断两直线是否平行

bool sameDir(L l0, L l1) { return parallel(l0, l1) && sign(l0.dir().dot(l1.dir()) ) == 1; }//判断两射线是否同向

bool cmp (P a,  P b) {
	if (a.quad() != b.quad()) {
		return a.quad() < b.quad();
	} else {
		return sign( a.det(b) ) > 0;
	}
}

bool operator < (L l0, L l1) {
	if (sameDir(l0, l1)) {
		return l1.include(l0[0]);
	} else {
		return cmp( l0.dir(), l1.dir() );
	}
}

bool check(L u, L v, L w) {
	return w.include(isLL(u,v));
}

vector<P> halfPlaneIS(vector<L> &l) {//求半平面交
	sort(l.begin(), l.end());
	deque<L> q;
	for (int i = 0; i < (int)l.size(); ++i) {
 		if (i && sameDir(l[i], l[i - 1])) continue;
 		while (q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
 		while (q.size() > 1 && !check(q[1], q[0], l[i])) q.pop_front();
 		q.push_back(l[i]);
 	}
	while (q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
	while (q.size() > 2 && !check(q[1], q[0], q[q.size() - 1])) q.pop_front();
	vector<P> ret;
	for (int i = 0; i < (int)q.size(); ++i) ret.push_back(isLL(q[i], q[(i + 1) % q.size()]));
	return ret;
}


int n;
const int maxn = 50000 + 5;
int x[maxn],y[maxn];
P p[maxn];


bool check(int len){
	vector <L> v;
	for(int i = 0;i < n;i++){
		L tmp;
		tmp[0] = p[i],tmp[1] = p[(i - len - 1 + n) % n];
		v.push_back(tmp);
	}
	vector <P> ret = halfPlaneIS(v);
	if(ret.size() <= 2) return true;
	return false;
}

int main(){
	freopen("jungle.in","r",stdin);
	freopen("jungle.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d%d",&x[i],&y[i]);
		p[i] = P(x[i],y[i]);
	}
	int l = 1,r = n - 2;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
