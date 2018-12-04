#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef double db;
const db eps = 1e-8;

inline int sign(db a){
	return a < -eps ? -1 : a > eps;
}

struct P{
	db x,y,z;
	P(){}
	P(db _x,db _y,db _z):x(_x),y(_y),z(_z){}
	P operator + (P p) {return P(x + p.x,y + p.y,z + p.z);}
	P operator - (P p) {return P(x - p.x,y - p.y,z - p.z);}
	P operator * (db d){return P(x * d,y * d,z * d);}
	db abs(){
		return sqrt(x * x + y * y + z * z);
	}
	void read(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}	
}p[4];
db r[2];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
	p[0].read();
	cin >> r[0];
	p[1].read();
	p[2].read();
	cin >> r[1];
	p[3].read();
	P v = p[2] - p[0];
	v = v * (r[0] / (r[0] + r[1]));
	P d = p[0] + v;
	db ans = 2.0 * asin((p[1] - d).abs() / 2 / r[0]) * r[0] + 2.0 * asin((p[3] - d).abs() / 2 / r[1]) * r[1];
	printf("%.4lf\n",ans);	
	}
	return 0;
}
