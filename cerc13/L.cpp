#include <cstdio>


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);
		long long x = 0;
		for(int i = 1;i <= k;i++){
			x = x * 2 + 1;
		}
		printf("%lld\n",x);
	}
	return 0;
}
