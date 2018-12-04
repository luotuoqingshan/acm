#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef double db;

const db EPS = 1e-8;

inline int sign(db a){
	return a < -EPS ? -1 : a > EPS;
}

inline int cmp(db a,db b){
	return sign(a - b);
}

struct P{
	db x,y;
	P(){}
	P(db _x,db _y): x(_x),y(_y){}
	P operator - (P p) {return P(x - p.x,y - p.y);}
	db det(P p){return x * p.y - y * p.x;}
	void read(){
		scanf("%lf%lf",&x,&y);
	}
};


struct L{
	P ps[2];
	P & operator[](int i){return ps[i];}
	bool on(P p){
		return sign((p - ps[0]).det(p - ps[1])) == 0;
	}
};

const int maxn = 1e5 + 5;

int n,m;
P p[maxn];

int main(){
	srand(time(NULL));
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		p[i].read();
	}
	if(n == 1){
		printf("possible\n");
		return 0;
	}
	bool flag = false;
	for(int i = 1;i <= 1000;i++){
		int j = 1LL * rand()  * rand() % n + 1;
		int k = 1LL * rand()  * rand() % n + 1;
		if(j == k) continue;
		L l;
		l[0] = p[j];
		l[1] = p[k];
		int num = (n * m + 99) / 100;
		int tmp = 0;
		for(int x = 1;x <= n;x++){
			if(l.on(p[x])) tmp++;
		}
		if(tmp >= num){
			flag = true;
			break;
		}
	}	
	if(flag) cout << "possible" << endl;
	else cout << "impossible" << endl;
	return 0;
}
