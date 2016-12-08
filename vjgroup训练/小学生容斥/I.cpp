#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n,m;

const int maxn = 400000 + 5;
int a[maxn];
int b[maxn];
int cnt;
int divi[maxn];

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		cnt = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 1;i <= m;i++){
			int op;
			scanf("%d",&op);
			if(op == 1){
				int l,r,p;
				scanf("%d%d%d",&l,&r,&p);
				int tot = 0;
				int tmp = p;
				for(int j = 2;j * j <= p;j++){
					if(tmp % j == 0){
						divi[tot++] = j;
						while(tmp % j == 0) tmp /= j;
					}
				}
				if(tmp > 1) divi[tot++] = tmp;
				long long ans = 0;
				for(int j = 0;j < (1 << tot);j++){
					int ret = 1,num = 0;
					for(int k = 0;k < tot;k++){
						if((j >> k) & 1) ret *= divi[k],num++;
					}
					long long F = r / ret;
					long long G = (l - 1) / ret;
					long long res = F * (F + 1) * ret / 2;
					res -= G * (G + 1) * ret / 2;
					if(num & 1) ans -= res;
					else ans += res;
				}
				sort(b + 1,b + 1 + cnt);
				if(cnt == 0 || b[1] > r || b[cnt] < l){}
				else{
					int s = lower_bound(b + 1,b + 1 + cnt,l) - b;
					for(int j = s;j <= cnt && b[j] <= r;j++){
						int n1 = __gcd(a[b[j]],p);
						int n2 = __gcd(b[j],p);
						if(n2 == 1) ans -= b[j];
						if(n1 == 1) ans += a[b[j]];
					}
				}
				cout << ans << endl;	
			}else{
				int p,c;
				scanf("%d%d",&p,&c);
				if(p == c && a[p] == 0) continue;
				if(a[p] == 0) b[++cnt] = p;
				a[p] = c;
			}
		}
	}
	return 0;
}
