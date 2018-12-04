#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n,a,b;
const int maxn = 105;
int p[maxn],q[maxn],s[maxn];
typedef double db;
const db eps = 1e-9;

db cal(db t){
	db ans = t * b;
	for(int i = 1;i <= n;i++){
		db t1 = max(0.0,(p[i] - t * s[i]) / q[i]);
		ans += t1 * a;
	}
	return ans;
}

int main(){
	freopen("academy.in","r",stdin);
	freopen("academy.out","w",stdout);
	cin >> n >> a >> b;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d",p + i,q + i,s + i);
	}
	db l = 0.0,r = 10000.0;
	for(int i = 1;i <= 1000;i++){
		db lmid = (l + l + r) / 3;
		db rmid = (r + r + l) / 3;
		if(cal(lmid) < cal(rmid) - eps){
			r = rmid;
		}else{
			l = lmid;
		}
	}	
	printf("%.10lf\n",cal((l + r) / 2));
	printf("%.10lf\n",(l + r) / 2);
	for(int i = 1;i <= n;i++){
		printf("%.10lf%c",max(0.0,(p[i] - l * s[i]) / q[i]),i == n ? '\n' : ' ');
	}
	return 0;
}
