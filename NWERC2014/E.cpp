#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int n;
typedef long double db;
db p,s,v;
 
db cal(db c){
	db a = log(n) / log(2);
	a = pow(a,c * sqrt(2));
	a = a * n;
	a /= (p * 1e9);
	db b = s * (1 + 1 / c) / v;
	return a + b;
}

const db eps = 1e-14;

int main(){
	cin >> n >> p >> s >> v;
	db l = 0.0,r = 100;
	for(int i = 1;i <= 10000;i++){
		db ll = (l + l + r) / 3;
		db rr = (r + r + l) / 3;

		if(cal(ll) < cal(rr) + eps){
			r = rr;	
		}else l = ll;
	}	
	printf("%.15Lf %.15Lf\n",cal(l),l);
	return 0;
}
