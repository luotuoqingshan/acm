#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int vis[maxn],mu[maxn],prime[maxn];
int cnt;

void init(){
	memset(vis,0,sizeof(vis));
	mu[1] = 1;
	cnt = 0;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0;j < cnt && i * prime[j] < maxn; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else{
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

long long F[maxn],f[maxn];
int a,b,c,d,k;


long long calc(int a,int b){
	for(int i = 1;i <= min(a,b);i++){
		F[i] = (long long) a / i * (long long)(b / i);
	}
	long long ans = 0;
	for(int i = k;i <= min(a,b);i += k){
		ans += (long long) mu[i / k] * F[i];
	}
	return ans;
}	

long long work(int a,int b){
	return calc(a,b) - (calc(min(a,b),min(a,b)) - (k <= min(a,b))) / 2;
}

int main(){
	int T;
	cin >> T;
	int cas = 0;
	init();
	while(T--){
		cin >> a >> b >> c >> d >> k;
		if(k == 0){
			printf("Case %d: ",++cas);
			cout << 0 << endl;
			continue;
		}
		//cout << calc(3,5) << endl;
		long long ans = 0;
		ans = work(b,d) - work(b,c - 1) - work(a - 1,d) + work(a - 1,c - 1);
		printf("Case %d: ",++cas);
		cout << ans << endl;
	}
	return 0;
}
