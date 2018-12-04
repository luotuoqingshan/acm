#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

typedef long double db;
const db eps = 1e-9;
const db pi = acos(-1);

db sqr(db x){
	return x * x;
}

int sgn(db x){
	return (x < -eps) ? -1 : (x > eps);
}

struct P{
	db x,y,z;
	P(){}
	P(db x,db y,db z):x(x),y(y),z(z){}
	db det(P b){
		return x * b.x + y * b.y + z * b.z;
	}
	void read(){
		cin >> x >> y >> z;
	}
	db distto(P a){
		return sqr(x - a.x) + sqr(y - a.y) + sqr(z - a.z);
	}
}p1,p2;

int r,d;

P substract(P a,P b){
	return P(a.x - b.x,a.y - b.y,a.z - b.z);
}

db dis(P a,P b,P c){
	db dis = sqrt(a.distto(b));
	return 2 * r * asin(dis / (2 * r));

}

P o,o1;

db cal(db mid,int t1){
	db tz = 1.0 * d / 2;
	db tr = sqrt(r * r - tz * tz);
	db tx = tr * sin(mid);
	db ty = tr * cos(mid);
	if(t1 == 0){
		db d1 = dis(p1,P(tx,ty,tz),o);
		db d2 = dis(p2,P(tx,ty,tz),o1);
		return d1 + d2;
	}else{
		db d1 = dis(p1,P(tx,ty,tz),o1);
		db d2 = dis(p2,P(tx,ty,tz),o);
		return d1 + d2;	
	}
}

const db delta = 0.25;


int main(){
//	freopen("path.in","r",stdin);
//	freopen("path.out","w",stdout);
	cin >> r >> d;
	p1.read(),p2.read();
	o = P(0,0,0), o1 = P(0,0,d);
	int t1,t2;
	if(p1.distto(o) < p1.distto(o1) - eps) t1 = 0;
	else t1 = 1;
	if(p2.distto(o) < p2.distto(o1) - eps) t2 = 0;
	else t2 = 1;
	if(t1 == t2){
		if(t1 == 0){
			printf("%.17Lf\n",dis(p1,p2,o));
		}else{
			printf("%.17Lf\n",dis(p1,p2,o1));
		}
	}else{
		db ans = 1e18;
		for(db alpha = 0;alpha <= 4 * pi;alpha += delta){
			db l = alpha,r = alpha + delta;
		   	for(int i = 1;i <= 1000;i++){
				db lmid = (l + l + r) / 3;
				db rmid = (r + r + l) / 3;
				if(cal(lmid,t1) < cal(rmid,t1)){
					r = rmid;
				}else l = lmid;
			}	
			ans = min(ans,cal(l,t1));
		}
		printf("%.17Lf\n",ans);
	}	

	return 0;
}
