#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


const int maxn = 305;

int f[maxn * 2][maxn * 2];
const int INF = (1 << 30) - 1;
int t[maxn * 2],tot;

int a[maxn],b[maxn],d[maxn];
int n;
int cal(int l,int r){
	if(f[l][r] != -1) return f[l][r];
	int &res = f[l][r];
	res = INF;
	int p = 0;
	for(int i = 1;i <= n;i++){
		if(l <= a[i] && b[i] <= r){
			if(d[i] > d[p]) p = i;
		}	
	}
	if(p == 0) return res = 0;
	for(int i  = a[p];i <= b[p];i++)
		res = min(res,cal(l,i - 1) + d[p] + cal(i + 1,r));
	return res;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		memset(f,-1,sizeof(f));
		tot = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i],&b[i],&d[i]);
			t[++tot] = a[i];t[++tot] = b[i];
		}
		sort(t + 1,t + 1 + tot);
		tot = unique(t + 1,t + 1 + tot) - t - 1;
		for(int i = 1;i <= n;i++){
			a[i] = lower_bound(t + 1,t + 1 + tot,a[i]) - t;
			b[i] = lower_bound(t + 1,t + 1 + tot,b[i]) - t;
		}
		printf("%d\n",cal(1,tot));
		/*for(int i = 1;i <= tot;i++){
			for(int j = i;j <= tot;j++){
				cout << i << " " << j << " " << f[i][j] << endl;
			}
		}*/
	}
	return 0;
}
