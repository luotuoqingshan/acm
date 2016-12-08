#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 100;

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

typedef long long ll;

ll F[maxn],f[maxn];

ll cal(ll x){
	if(x == 1) return 0;
	memset(F,0,sizeof(F));
	memset(f,0,sizeof(f));
	for(int i = 1;i <= 70;i++){
		F[i] = (ll)(pow(x,1.0 / i) + 1e-10) - 1;
	}
	for(int i = 1;i <= 70;i++){
		for(int j = i;j <= 70;j += i){
			f[i] += mu[j / i] * F[j];
		}
	}
	//for(int i = 1;i <= 10;i++){
	//	cout << f[i] << " ";
	//}
	//cout << endl;
	ll ans = 0;
	for(int i = 1;i <= 70;i++){
		ans = ans + (ll) i * f[i];
	}
	return ans;
}

int main(){
	ll a,b;
	init();
	while(cin >> a >> b){
		if(a == 0 && b == 0) break;
		//cout << cal(10) << endl;
		ll ans = cal(b) - cal(a - 1);
		cout << ans << endl;
	}
	
	return 0;
	
}
	
