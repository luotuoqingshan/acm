#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>


using namespace std;

const int maxn = 5e6 + 5;
const int mod = 100000073;

int f[maxn],sum[maxn];
int pre[maxn];
int val[10005];
void upd(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

void init(){
	for(int i = 0;i <= 10000;i++){
		val[i] = i * (i + 1) / 2;
	}
}

int Sum(int x){
	if(x < 0) return 0;
	return pre[x];
}

int main(){
	init();
	f[0] = 0,sum[0] = 1;pre[0] = 1;
	f[1] = 1,sum[1] = 1;pre[1] = 2;
	for(int i = 2;i < maxn;i++){
		int x = lower_bound(val + 1,val + 10000,i) - val;
		f[i] = x;
		sum[i] = 0;
		upd(sum[i],Sum(val[x - 1]));
		upd(sum[i],-Sum(i - f[i] - 1));
		pre[i] = sum[i];
		upd(pre[i],pre[i - 1]);
	}	
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF){
		int n = b - a + 1;
		printf("%d %d\n",f[n],sum[n]);
	}
	return 0;
}
