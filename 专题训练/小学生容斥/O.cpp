#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int mod = 10007;

const int maxn = 10005;

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

int num[maxn];
int n;

int F[maxn],f[maxn];
int G[maxn];


int main(){
	init();
	while(cin >> n){
		memset(num,0,sizeof(num));
		for(int i = 1;i <= n;i++){
			int a;
			scanf("%d",&a);
			num[a]++;
		}
		memset(G,0,sizeof(G));
		memset(f,0,sizeof(f));
		memset(F,0,sizeof(F));
		for(int i = 1;i <= 10000;i++){
			for(int j = i;j <= 10000;j += i){
				G[i] += num[j];
			}
			F[i] = (long long) G[i] * G[i] % mod;
		}
		for(int i = 1;i <= 10000;i++){
			for(int j = i;j <= 10000;j += i){
				f[i] = (f[i] + mu[j / i] * F[j] % mod + mod) % mod;
			}
		}
		/*for(int i = 1;i <= 5;i++){
			cout << f[i] << " ";
		}*/
		long long ans = 0;
		for(int i = 1;i <= 10000;i++){
			ans = (ans + (long long) (i - 1) * i % mod * f[i] % mod) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}
