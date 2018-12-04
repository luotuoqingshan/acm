#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int maxn = 1e5 + 5;

typedef long double db;
const db eps = 1e-15;
const db INF = 1e18;
int n;

int sgn(db x){
	return x < -eps ? -1 : x > eps;
}

struct line{
	db k,b;
	bool operator < (const line & rhs) const{
		if(sgn(k - rhs.k) == 0) return b > rhs.b + eps;
		return k < rhs.k - eps;
	}
	void read(){
		scanf("%Lf%Lf",&k,&b);
	}
}l[maxn];

db calx(line a,line b){
	return (b.b - a.b) / (b.k - a.k);
}

db caly(line a,line b){
	return (a.k * b.b - b.k * a.b) / (b.k - a.k);	
}

bool cmp(line a,line b){
	if(sgn(a.k) != sgn(b.k)) return sgn(a.k) < sgn(b.k);
	if(sgn(a.k) > 0){
		if(sgn(a.k - b.k) == 0) return a.b < b.b - eps;
		else return a.k > b.k + eps;	
	}else{
		if(sgn(a.k - b.k) == 0) return a.b > b.b + eps;
		else return a.k > b.k + eps;
	}	
	return 0;
}


bool cmp1(line a,line b){
	if(sgn(a.k - b.k) == 0) return a.b < b.b - eps;
	return a.k < b.k - eps;
}


bool cmp2(line a,line b){
	if(sgn(a.k) != sgn(b.k)) return sgn(a.k) < sgn(b.k);
	if(sgn(a.k) > 0){
		if(sgn(a.k - b.k) == 0) return a.b > b.b + eps;
		else return a.k > b.k + eps;
	}else{
		if(sgn(a.k - b.k) == 0) return a.b < b.b - eps;
		else return a.k > b.k + eps;
	}
	return 0;
}


int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		l[i].read();		
	}	
	db xr = -INF;
	sort(l,l + n);
	for(int i = 0;i < n - 1;i++){
		if(sgn(l[i].k - l[i + 1].k) == 0) continue;
		db tmp = calx(l[i],l[i + 1]);
		xr = max(xr,tmp);
	}
	db yr = -INF;
	sort(l,l + n,cmp);
	for(int i = 0;i < n - 1;i++){
		if(sgn(l[i].k - l[i + 1].k) == 0) continue;
		db tmp = caly(l[i],l[i + 1]);
		yr = max(yr,tmp);
	}
	db xl = INF;
	sort(l,l + n,cmp1);
	for(int i = 0;i < n - 1;i++){
		if(sgn(l[i].k - l[i + 1].k) == 0) continue;
		db tmp = calx(l[i],l[i + 1]);
		xl = min(xl,tmp);
	}
	db yl = INF;
	sort(l,l + n,cmp2);
	for(int i = 0;i < n - 1;i++){
		if(sgn(l[i].k - l[i + 1].k) == 0) continue;
		db tmp = caly(l[i],l[i + 1]);
		yl = min(yl,tmp);
	}
	printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",xl,yl,xr,yr);
	return 0;
}
