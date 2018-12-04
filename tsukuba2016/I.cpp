#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
LL x,y;

LL gcd(LL a,LL b){
	return b == 0 ? a : gcd(b,a % b);
}

void gcd(LL a,LL b,LL &d,LL &x,LL &y){
	if(!b) {d = a;x = 1;y = 0;}
	else{ gcd(b,a % b,d,y,x);y -= x * (a / b);}
}


int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%lld%lld\n",&x,&y);
		LL g = gcd(x,y);
		if(g <= 50000){
			LL a,b,d;
			gcd(x,y,d,a,b);
			printf("3\n");
			printf("0 0\n");
			printf("%lld %lld\n",x,y);
			if(a <= 0) printf("%lld %lld\n",b,-a);
			else printf("%lld %lld\n",-b,a);
		}else{
			printf("4\n");
			printf("%lld %lld\n",0,0);
			printf("%lld %lld\n",x - 1,y);
			printf("%lld %lld\n",x / g,y / g);	
			printf("%lld %lld\n",x,y - 1);
		}
	}
	return 0;
}
