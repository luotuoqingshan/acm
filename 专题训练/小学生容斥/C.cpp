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

int n,m;

long long f[maxn],F[maxn];

int main(){
	init();
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d",&n,&m);
		int l = min(n,m);
		for(int i = 1;i <= l;i++){
			F[i] = (long long) (n / i) * (long long)(m / i);
		}
		long long ans = 0;
		for(int i = 1;i <= l;i++){
			ans += mu[i] * F[i];
		}
		cout << ans << endl;
	}
	return 0;
}
