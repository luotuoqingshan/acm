#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 10005;
typedef long long ll;

int n;
int num[maxn];
int G[maxn];
ll F[maxn];

//Mu template

//const int maxn = 10005;

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

//


int main(){
	init();
	while(cin >> n){
		memset(num,0,sizeof(num));
		memset(G,0,sizeof(G));
		memset(F,0,sizeof(F));
		//memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++){
			int a;
			scanf("%d",&a);
			num[a]++;
		}
		for(int i = 1;i <= 10000;i++){
			for(int j = i;j <= 10000;j += i){
				G[i] += num[j];
			}
			F[i] = (long long) G[i] * (G[i] - 1) / 2 * (G[i] - 2) / 3 * (G[i] - 3) / 4;
		}
		long long ans = 0;
		/*for(int i = 1;i <= 10;i++){
			cout << F[i] << " ";
		}*/
		for(int i = 1;i <= 10000;i++){
			ans += mu[i] * F[i];
		}
		cout << ans << endl;
	}
	return 0;
}
