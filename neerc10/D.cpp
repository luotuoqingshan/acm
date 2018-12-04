#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long double db;

const db eps = 1e-10;
const db INF = 1e18;

const int maxn = 1e4 + 5;
const db pi = acos(-1);
db x[maxn],y[maxn],z[maxn];

int n;

db cal(db h){
	db r2 = 0;
	for(int i = 1;i <= n;i++){
		r2 = max(r2,(h / (h - z[i])) * (h / (h - z[i])) * (x[i] * x[i] + y[i] * y[i]));	
	}
	return r2 * h * pi / 3;
}

int main(){
	cin >> n;
	db l = -INF,r;
	for(int i = 1;i <= n;i++){
		scanf("%Lf%Lf%Lf",x + i,y + i,z + i);
		l = max(l,z[i]);
	}	
	l = l + eps,r = INF;
	for(int i = 1;i <= 200;i++){
		db lmid = (l + l + r) / 3;	
		db rmid = (r + r + l) / 3;
		if(cal(rmid) > cal(lmid) - eps) l = lmid;
		else r = rmid;
	}	
	printf("%.3Lf\n",cal((l + r) / 2));
	return 0;
}
